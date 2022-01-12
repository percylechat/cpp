#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR

#include <memory> // allocator and ptrdiff_t
#include "iterator.hpp"

namespace ft {

template<typename Iterator>
class reverse_iterator{
	public:
		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::reference reference;
	private:
		iterator_type _ite;
	public:
////////////////////////////////////////////////////////////////////////
// CONSTRUCTEURS / DESTRUCTEUR
////////////////////////////////////////////////////////////////////////
		reverse_iterator(){
			this->_ite = NULL;
		}
		reverse_iterator(iterator_type p){
			this->_ite = p;
		}
		template <typename ITE>
		reverse_iterator(const reverse_iterator<ITE>& one){
			this->_ite = one.base();
		}
		reverse_iterator& operator=(const reverse_iterator & one) {
			this->_ite = one.base();
			return *this;
		}
		~reverse_iterator() {}
////////////////////////////////////////////////////////////////////////
// REF AND POINT
////////////////////////////////////////////////////////////////////////
		iterator_type base(void) const {
			return _ite;
		}
		reference operator*() const{
			iterator_type it = this->_ite;
			it--;
			return *it;
		}
		pointer operator->()const{
			return &(operator*());
		}
		value_type& operator[](int index) {
			return *(this->_ite - index - 1);
		}
////////////////////////////////////////////////////////////////////////
// OPERATIONS
////////////////////////////////////////////////////////////////////////
		reverse_iterator &operator++(){
			this->_ite--;
			return *this;
		}
		reverse_iterator operator++(int){
			reverse_iterator temp = *this;
			this->_ite--;
			return temp;
		}
		reverse_iterator &operator--(){
			this->_ite++;
			return *this;
		}
		reverse_iterator operator--(int){
			reverse_iterator temp = *this;
			this->_ite++;
			return temp;
		}
		reverse_iterator &operator+=(difference_type nbr){
			this->_ite -= nbr;
			return *this;
		}
		reverse_iterator &operator-=(difference_type nbr){
			this->_ite += nbr;
			return *this;
		}
		friend reverse_iterator<Iterator> operator+(difference_type nbr, const reverse_iterator& one){
			return one._ite - nbr;
		}
		reverse_iterator<Iterator> operator+(difference_type nbr)const{
			return this->_ite - nbr;
		}
		reverse_iterator<Iterator> operator-(difference_type nbr) const{
			return this->_ite + nbr;
		}
		difference_type operator-(const reverse_iterator & one) const{
			return one._ite - this->_ite;
		}
////////////////////////////////////////////////////////////////////////
// COMPARE
////////////////////////////////////////////////////////////////////////
		bool operator!=(const reverse_iterator bis) const{
			if (this->_ite != bis._ite)
				return true;
			return false;
		}
		bool operator==(const reverse_iterator bis) const{
			if (this->_ite == bis._ite)
				return true;
			return false;
		}
		bool operator>(const reverse_iterator bis) const{
			if (this->_ite < bis._ite)
				return true;
			return false;
		}
		bool operator>=(const reverse_iterator bis) const{
			if (this->_ite <= bis._ite)
				return true;
			return false;
		}
		bool operator<=(const reverse_iterator bis) const{
			if (this->_ite >= bis._ite)
				return true;
			return false;
		}
		bool operator<(const reverse_iterator bis) const{
			if (this->_ite > bis._ite)
				return true;
			return false;
		}
};

template <typename T>
reverse_iterator<T> & operator+(typename reverse_iterator<T>::difference_type n,
const reverse_iterator<T>& it) {
	return it + n;
}
template <typename T>
reverse_iterator<T> & operator-(typename reverse_iterator<T>::difference_type n,
const reverse_iterator<T>& it) {
	return it - n;
}

template<typename it1, typename it2>
bool operator==(const reverse_iterator<it1>& one, const reverse_iterator<it2>& two) {
	return (one.base() == two.base());
}
template<typename it1, typename it2>
bool operator!=(const reverse_iterator<it1>& one, const reverse_iterator<it2>& two) {
	return (one.base() != two.base());
}
template<typename it1, typename it2>
bool operator<(const reverse_iterator<it1>& one, const reverse_iterator<it2>& two) {
	return one.base() > two.base();
}
template<typename it1, typename it2>
bool operator<=(const reverse_iterator<it1>& one, const reverse_iterator<it2>& two) {
	return one.base() >= two.base();
}
template<typename it1, typename it2>
bool operator>(const reverse_iterator<it1>& one, const reverse_iterator<it2>& two) {
	return one.base() < two.base();
}
template<typename it1, typename it2>
bool operator>=(const reverse_iterator<it1>& one, const reverse_iterator<it2>& two) {
	return one.base() <= two.base();
}

}
#endif // !REVERSE_ITERATOR