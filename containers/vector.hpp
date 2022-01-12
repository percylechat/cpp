#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory> //allocator
#include <iterator>
#include <stdexcept> //OOB exception
#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft {

template < class T, class Alloc = std::allocator<T> > class vector{
//dans template, alloc deja precise pour pas avoir a le remettre
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		// typedef &value_type reference;
		typedef typename allocator_type::reference reference;
		// typedef const &value_type const_reference;
		typedef typename allocator_type::const_reference const_reference;
		// typedef *value_type pointer;
		typedef typename allocator_type::pointer pointer;
		// typedef const *value_type const_pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		// typedef size_t size_type;
		typedef typename allocator_type::size_type size_type;
		// typedef ptrdiff_t difference_type;
		typedef typename allocator_type::difference_type difference_type;
		typedef vector_iterator<value_type> iterator;
		typedef vector_iterator<value_type const> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
////////////////////////////////////////////////////////////////////////
// CONSTRUCTEURS / DESTRUCTEUR
////////////////////////////////////////////////////////////////////////
		explicit vector(){
			this->_data = NULL;
			this->_usage = 0;
			this->_capacity = 0;
		}
		explicit vector(size_type n, const value_type& val = value_type(),
				 const allocator_type& alloc = allocator_type()){
			this->_alloc = alloc;
			this->_data = this->_alloc.allocate(n);
			size_type i = 0;
			while (i < n){
				this->_alloc.construct(&this->_data[i], val);
				i++;
			}
			this->_capacity = n;
			this->_usage = n;
		}
		template <class InputIterator>
		vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value_type, InputIterator>::type first
		, InputIterator last, const allocator_type& alloc = allocator_type()){
			InputIterator temp = first;
			unsigned int i = ite_size(first, last);
			size_type j = 0;
			this->_alloc =  alloc;
			this->_data = this->_alloc.allocate(i);
			temp = first;
			while (j != i){
				this->_alloc.construct(&this->_data[j], *temp);
				j++;
				temp++;
			}
			this->_capacity = i;
			this->_usage = i;
		}
		vector(const vector& x){
			this->_alloc = x._alloc;
			this->_data = this->_alloc.allocate(x._capacity);
			size_type i = 0;
			while (i < x._capacity){
				this->_alloc.construct(&this->_data[i], x._data[i]);
				i++;
			}
			this->_capacity = x._capacity;
			this->_usage = x._usage;
		}
		vector& operator=(const vector& x) {
			this->reserve(x._usage);
						this->assign(x.begin(), x.end());
			return *this;
		}
		~vector(){
			size_type i = 0;
			while (i < this->_usage){
				this->_alloc.destroy(&this->_data[i]);
				i++;
			}
			this->_alloc.deallocate(this->_data, this->_capacity);
		}
////////////////////////////////////////////////////////////////////////
// ITERATOR
////////////////////////////////////////////////////////////////////////
		iterator begin(){
			return vector_iterator<value_type>(this->_data);
		}
		const_iterator begin() const{
			return const_iterator(this->_data);
		}
		iterator end(){
			return vector_iterator<value_type>(this->_data + this->_usage);
		}
		const_iterator end() const{
			return const_iterator(this->_data + this->_usage);
		}
		reverse_iterator rbegin(){
			return reverse_iterator(this->_data + this->_usage);
		}
		const_reverse_iterator rbegin() const{
			return const_reverse_iterator(this->_data + this->_usage);
		}
		reverse_iterator rend(){
			return reverse_iterator(this->_data);
		}
		const_reverse_iterator rend() const{
			return const_reverse_iterator(this->_data);
		}
////////////////////////////////////////////////////////////////////////
// SIZE AND CAPACITY
////////////////////////////////////////////////////////////////////////
		bool empty() const{
			if (this->_usage == 0)
				return true;
			return false;
		}
		size_type size() const{
			return this->_usage;
		}
		size_type max_size() const{
			return this->_alloc.max_size();
		}
		void resize (size_type n, value_type val = value_type()){
			if (n < this->_usage){
				size_type j = n;
				while (n != this->_usage){
					this->_alloc.destroy(&this->_data[n]);
					n++;
				}
				this->_usage = j;
			}
			else{
				size_type i = 0;
				size_type j = this->_usage;
				// std::cout << n - j << std::endl;
				while (i < n - j){
					push_back(val);
					i++;
				}
			}
		}
		void reserve (size_type n){
			if (n > this->_capacity){
				size_type z = this->_capacity;
				pointer buf = this->alloc(n);
				size_type i = 0;
				while (i < this->_usage){
					this->_alloc.construct(&buf[i], this->_data[i]);
					i++;
				}
				this->_alloc.deallocate(this->_data, z);
				this->_data = buf;
			}
		}
		size_type capacity() const{
			return this->_capacity;
		}
////////////////////////////////////////////////////////////////////////
// ACCESS TO ELEMENTS IN VECTOR
////////////////////////////////////////////////////////////////////////
		reference operator[](size_type n){
			return this->_data[n];
		}
		reference at(size_type n){
			if (n >= this->_usage)
				throw std::out_of_range("Not Found");
			return this->_data[n];
		}
		const_reference at(size_type n) const{
			if (n >= this->_usage)
				throw std::out_of_range("Not Found");
			return this->_data[n];
		}
		reference front(){
			return this->_data[0];
		}
		const_reference front() const{
			return this->_data[0];
		}
		reference back(){
			return this->_data[this->_usage - 1];
		}
		const_reference back() const{
			return this->_data[this->_usage - 1];
		}
////////////////////////////////////////////////////////////////////////
// MODIFY
////////////////////////////////////////////////////////////////////////
		template <class InputIterator>
		void assign (typename ft::enable_if<!ft::is_integral<InputIterator>::value_type, InputIterator>::type first,
		InputIterator last){
			InputIterator temp = first;
			size_type i = 0;
			while (temp != last){
				temp++;
				i++;
			}
			this->clear();
			if (this->_capacity < i)
				this->_data = this->alloc(i - this->_capacity);
			i = 0;
			while (first != last){
				this->_alloc.construct(&this->_data[i], *first);
				first++;
				i++;
				this->_usage++;
			}
		}
		void assign (size_type n, const value_type& val){
			this->clear();
			if (this->_capacity < n)
				this->_data = this->alloc(n - this->_capacity);
			size_type i = 0;
			while (i < n){
				this->_alloc.construct(&this->_data[i], val);
				i++;
			}
			this->_usage = n;
		}
		void push_back(const value_type& val){
			this->insert(this->end(), val);
		}
		void pop_back(){
			this->_alloc.destroy(&this->_data[this->_usage - 1]);
			this->_usage--;
		}
		iterator insert( iterator pos, const value_type& value ){
			this->insert(pos, 1, value);
			size_type i = 0;
			while (this->_data[i] != value)
				i++;
			return iterator(&this->_data[i]);
		}
		void insert(iterator pos, size_type count, const value_type& value ){
			size_type i = 0;
			size_type j = 0;
			size_type k = 0;
			size_type l = 0;
			iterator start = this->begin();
			while (start != pos){
					i++;
					start++;
			}
			while (start != this->end()){
				j++;
				start++;
			}
			if (this->_usage + count > this->_capacity)
				this->reserve(this->_capacity + count);
			while (k < j){
				this->_alloc.construct(&this->_data[i + count + j - k - 1], this->_data[i + j - k - 1]);
				this->_alloc.destroy(&this->_data[i + j - k - 1]);
				k++;
			}
			while (l < count){
				this->_alloc.construct(&this->_data[i + l], value);
				l++;
			}
			this->_usage += count;
		}
		template< class InputIterator >
		void insert( iterator pos, typename ft::enable_if<!ft::is_integral<InputIterator>::value_type,
		InputIterator>::type first, InputIterator last ){
			size_type i = 0;
			size_type j = 0;
			size_type k = 0;
			size_type l = 0;
			size_type count = 0;
			iterator start = this->begin();
			InputIterator cp = first;
			while (cp != last){
				cp++;
				count++;
			}
			while (start != pos){
				i++;
				start++;
			}
			while (start != this->end()){
				j++;
				start++;
			}
			if (this->_usage + count > this->_capacity)
				this->reserve(this->_capacity + count);
			while (k < j){
				this->_alloc.construct(&this->_data[i + count + j - k - 1], this->_data[i + j - k - 1]);
				this->_alloc.destroy(&this->_data[i + j - k - 1]);
				k++;
			}
			while (l < count){
				this->_alloc.construct(&this->_data[i + l], *first);
				first++;
				l++;
			}
			this->_usage += count;
		}
		iterator erase( iterator pos ){
			return this->erase(pos, pos + 1);
		}
		iterator erase( iterator first, iterator last ){
			size_type i = 0;
			size_type j = 0;
			size_type k = 0;
			size_type count = 0;
			iterator start = this->begin();
			iterator cp = first;
			while (cp != last){
				cp++;
				count++;
			}
			while (start != first){
				i++;
				start++;
			}
			start += count;
			while (start != this->end()){
				j++;
				start++;
			}
			while (k < j){
				this->_alloc.destroy(&this->_data[i + k]);
				this->_alloc.construct(&this->_data[i + k], this->_data[i + count + k]);
				k++;
			}
			k = 0;
			while (k < count){
				this->_alloc.destroy(&this->_data[i + j + k]);
				k++;
			}
			this->_usage -= count;
			return iterator(&this->_data[i]);
		}
		void swap (vector& x){
			allocator_type buf = this->_alloc;
			this->_alloc = x._alloc;
			x._alloc = buf;
			size_type a = this->_capacity;
			this->_capacity = x._capacity;
			x._capacity = a;
			size_type b = this->_usage;
			this->_usage = x._usage;
			x._usage = b;
			pointer c = this->_data;
			this->_data = x._data;
			x._data = c;
		}
		void clear(){
			pointer p = &this->_data[0];
			while (this->_usage > 0){
				this->_alloc.destroy(p + (this->_usage - 1));
				this->_usage--;
			}
		}
////////////////////////////////////////////////////////////////////////
// ALLOCATOR
////////////////////////////////////////////////////////////////////////
		allocator_type get_allocator() const{
			return this->_alloc;
		}
////////////////////////////////////////////////////////////////////////
// NON MEMBERS
////////////////////////////////////////////////////////////////////////
	private:
		size_type _capacity;
		size_type _usage;
		pointer _data;
		allocator_type _alloc;
		pointer alloc(size_type n)
		{
			size_type tot = this->_capacity + (n + (n / 2));
			pointer ret = this->_alloc.allocate(tot);
			this->_capacity = tot;
			return ret;
		}
		void copy_until(size_type n, pointer targ, pointer source)
		{
			size_type i = 0;
			while (i < n){
				this->_alloc.construct(&targ[i], source[i]);
				i++;
			}
		}
};

template <class T, class Alloc>
bool operator== (const vector<T, Alloc>& one, const vector<T, Alloc>& two) {
	if (one.size() != two.size())
		return false;
	return equal(one.begin(), one.end(), two.begin());
}
template <class T, class Alloc>
bool operator!= (const vector<T, Alloc>& one, const vector<T, Alloc>& two) {
	return !(one == two);
}
template <class T, class Alloc>
bool operator< (const vector<T, Alloc>& one, const vector<T, Alloc>& two) {
	return lexicographical_compare(one.begin(), one.end(), two.begin(), two.end());
}
template <class T, class Alloc>
bool operator<= (const vector<T, Alloc>& one, const vector<T, Alloc>& two) {
	return (one < two || one == two);
}
template <class T, class Alloc>
bool operator> (const vector<T, Alloc>& one, const vector<T, Alloc>& two) {
	return (two < one);
}
template <class T, class Alloc>
bool operator>= (const vector<T, Alloc>& one, const vector<T, Alloc>& two) {
	return (one > two || one == two);
}
template <class T, class Alloc>
void swap (vector<T, Alloc>& one, vector<T, Alloc>& two) {
	one.swap(two);
}

}
#endif // !VECTOR_HPP