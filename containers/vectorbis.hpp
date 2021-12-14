
#include <memory> //allocator
#include <iterator>
#include <stdexcept> //OOB exception
#include "iterator_vector.hpp"

template < class T, class Alloc = std::allocator<T> > class ft_vector{
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
        typedef iterator_vector<value_type> iterator;
        // typedef vector_iterator<value_type const> const_iterator;
        explicit ft_vector(){
            this->_data = NULL;
            this->_usage = 0;
            this->_capacity = 0;
        }
        explicit ft_vector(size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()){
            allocator_type alloca = alloc;
            this->_data = alloca.allocate(n);
            size_type i = 0;
            while (i < n){
                alloca.construct(&this->_data[i], val);
                i++;
            }
            this->_capacity = n;
            this->_usage = n;
        }
        template <class InputIterator>
        ft_vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
            InputIterator temp = first;
            size_type i = 0;
            while (temp != last){
                temp++;
                i++;
            }
            size_type j = 0;
            allocator_type alloca = alloc;
            this->_data = alloca.allocate(i);
            while (j != i){
                alloca.construct(&this->_data[j], first);
                j++;
                first++;
            }
            this->_capacity = i;
            this->_usage = i;
        }
        ft_vector(const ft_vector& x){
            //need x allocator!!!!!!
            allocator_type alloc = allocator_type();
            this->_data = alloc.allocate(x._capacity);
            size_type i = 0;
            while (i < x._capacity){
                alloc.construct(&this->_data[i], x._data[i]);
                i++;
            }
            this->_capacity = x._capacity;
            this->_usage = x._usage;
        }
        ~ft_vector(){
            allocator_type alloc = allocator_type();
            this->clear();
            alloc.deallocate(this->_data, this->_capacity);
        }
////////////////////////////////////////////////////////////////////////
// ITERATOR
////////////////////////////////////////////////////////////////////////
        iterator begin(){
            // If the container is empty, the returned iterator value shall not be dereferenced.
            return iterator_vector<value_type>(this->_data);
        }
        // const_iterator begin() const;
        iterator end(){
            return iterator_vector<value_type>(this->_data + this->_usage);
        }
    // const_iterator end() const;

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
            allocator_type alloc;
            return alloc.max_size();
        }
        void reserve (size_type n){
            if (n > this->_capacity)
            {
                pointer buf;
                allocator_type alloc = alloc;
                buf = alloc.allocate(n);
                size_type i = 0;
                while (i < this->_usage){
                    alloc.construct(&buf[i], this->_data[i]);
                    i++;
                }
                alloc.deallocate(this->_data, this->_capacity);
                this->_capacity = n;
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
            //doute si dernier elt peuple ou pas
            return this->_data[this->_usage - 1];
        }
        const_reference back() const{
            //doute si dernier elt peuple ou pas
            return this->_data[this->_usage - 1];
        }
////////////////////////////////////////////////////////////////////////
// MODIFY
////////////////////////////////////////////////////////////////////////
        void clear(){
            allocator_type alloc = allocator_type();
            pointer p = &this->_data[0];
            while(this->_usage < 0)
            {
                alloc.destroy(p+ (this->_usage - 1));
                this->_usage--;
            }
        }
        iterator insert( iterator pos, const T& value ){
            if (pos == this->end()){
                this->push_back(value);
                return pos--;
            }
            iterator temp = this->begin();
            if (this->_usage == this->_capacity){
                pointer buf; //je crée nv pointeur pr data
                allocator_type alloc = allocator_type(); //je cree allocateur
                buf = alloc.allocate(this->_capacity + 1); // j'utilise l allocateur pr allouer dans buf
                size_type i = 0;
                if (pos != this->begin()){
                    pos--;
                    while (temp != pos){
                        alloc.construct(&buf[i], this->_data[i]);
                        i++;
                        temp++;
                    }
                }
                alloc.construct(&buf[i], value);
                iterator ret = &buf[i];
                i++;
                while (temp != this->end()){
                    alloc.construct(&buf[i], this->_data[i]);
                    i++;
                    temp++;
                }
                if (this->_capacity == 0)
                    delete this->_data;
                else{
                    this->clear();
                    alloc.deallocate(this->_data, this->_capacity);
                }
                this->_data = buf;
                this->_usage++;
                this->_capacity++;
                return ret;
            }
            else{
                value_type buf;
                value_type buf1;
                while (temp != pos){
                    temp++;
                }
                temp--;
                buf = *temp;
                *temp = value;
                temp++;
                while (temp != this->end()){
                    buf1 = *temp;
                    *temp = buf;
                    buf = buf1;
                    temp++;
                }
                this->_usage++;
                return --pos;
            }
        }
        // void insert( iterator pos, size_type count, const T& value ){

        // }
        // template< class InputIt >
        // void insert( iterator pos, InputIt first, InputIt last );
        // iterator erase( iterator pos );
        // iterator erase( iterator first, iterator last );
                // template <class InputIterator>
        // void assign (InputIterator first, InputIterator last);
        void assign (size_type n, const value_type& val){
            if (this->_capacity < n){

            }
            else{
                allocator_type alloc = allocator_type();
                this->clear();
                size_type i = 0;
                while (i < n){
                    alloc.construct(&this->_data[i], val);
                    i++;
                }
            }
        }
        void push_back(const value_type& val){
            if (this->_usage == this->_capacity){
                pointer buf; //je crée nv pointeur pr data
                allocator_type alloc = allocator_type(); //je cree allocateur
                buf = alloc.allocate(this->_capacity + 1); // j'utilise l allocateur pr allouer dans buf
                size_type i = 0;
                while (i < this->_capacity){
                    alloc.construct(&buf[i], this->_data[i]);
                    i++;
                }
                alloc.construct(&buf[i], val);
                if (this->_capacity == 0)
                    delete this->_data;
                else{
                    this->clear();
                    alloc.deallocate(this->_data, this->_capacity);
                }
                this->_data = buf;
                this->_usage++;
                this->_capacity++;
            }
            else if (this->_usage < this->_capacity){
                this->_data[this->_usage] = val;
                this->_usage++;
            }
            else {std::cerr << "issue between size and usage in push_back";}
        }
        void pop_back(){
            this->_data[this->_size - 1] = NULL;
            this->_size--;
        }
        void resize (size_type n, value_type val = value_type()){
            size_type res = this->_usage - n;
            if (res >= 0){
                // a modif pour plus efficace?
                while (res != 0){
                    push_back(val);
                    res--;
                }
            }
            else{
                pointer buf;
                allocator_type alloc = alloc;
                buf = alloc.allocate(n);
                size_type i = 0;
                while (i < n){
                    alloc.construct(&buf[i], this->_data[i]);
                    i++;
                }
                alloc.deallocate(this->_data, this->_capacity);
                this->_capacity = n;
                this->_usage = n;
                this->_data = buf;
            }
        }
////////////////////////////////////////////////////////////////////////
// ALLOCATOR
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
// NON MEMBERS
////////////////////////////////////////////////////////////////////////
    private:
        size_type _capacity;
        unsigned int _usage;
        pointer _data;
        pointer alloc(size_type n, allocator_type alloc)
        {
            size_type tot = this->_capacity + (n + (n / 2));
            pointer ret = alloc.allocate(tot);
            return ret;
        }
};