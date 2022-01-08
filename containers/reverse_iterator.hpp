#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR

#include <memory> // allocator and ptrdiff_t
#include "vector_iterator.hpp"
#include "iterator.hpp"

namespace ft {

template<typename Iterator>
class reverse_iterator{
    // protected:
    // typedef iterator_traits<T> iterator_traits;

  public:
    // typedef typename iterator_traits::value_type value_type;
    // typedef typename iterator_traits::difference_type difference_type;
    // typedef typename iterator_traits::pointer pointer;
    // typedef typename iterator_traits::reference reference;
    typedef Iterator iterator_type;
    typedef typename iterator_traits<Iterator>::value_type value_type;
    typedef typename iterator_traits<Iterator>::difference_type difference_type;
    typedef typename iterator_traits<Iterator>::pointer pointer;
    typedef typename iterator_traits<Iterator>::reference reference;
    // typedef typename std::random_access_iterator_tag iterator_category;
//    pointer _ite;
    // private:

        // typedef T         value_type;
        // typedef std::ptrdiff_t difference_type;
        // typedef T* pointer;
        // typedef T& reference;
        pointer _ite;
    public:
////////////////////////////////////////////////////////////////////////
// CONSTRUCTEURS / DESTRUCTEUR
////////////////////////////////////////////////////////////////////////
        reverse_iterator(){
            this->_ite = NULL;
        }
        reverse_iterator(pointer p){
            this->_ite = p;
        }
        explicit reverse_iterator (iterator_type it){
            this->_ite = it.get_ptr();
        }
        template <typename ITE>
        reverse_iterator(const reverse_iterator<ITE>& one){
            this->_ite = one.get_ptr();
        }
        reverse_iterator& operator=(const reverse_iterator & one) {
            this->_ite = one.get_ptr();
            return *this;
        }
	    ~reverse_iterator() {}
        // operator reverse_iterator<value_type const>() const {
        //     return reverse_iterator<value_type const>(this->_ite);
        // }
        // operator reverse_iterator<vector_iterator<value_type> >() {
        //     return reverse_iterator<vector_iterator<value_type> >(_ite);
        // }
        // operator reverse_iterator<vector_iterator<value_type const> >() const {
        //     return reverse_iterator<vector_iterator<value_type const> >(_ite);
        //     }
	    // operator reverse_iterator<vector_iterator<value_type> >() {
        //     return reverse_iterator<vector_iterator<value_type> >(_ite);
        // }
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
        pointer operator->(){
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
            // difference_type i = 0;
            // while(i < nbr){
            //     this->_ite--;
            //     i++;
            // }
            this->_ite -= nbr;
            return *this;
        }
        reverse_iterator &operator-=(difference_type nbr){
            // difference_type i = 0;
            // while(i < nbr){
            //     this->_ite++;
            //     i++;
            // }
            this->_ite += nbr;
            return *this;
        }
        reverse_iterator operator+(difference_type nbr){
            return this->_ite - nbr;
        }
        difference_type operator+(const reverse_iterator & one) const{
            return this->_ite - one._ite;
        }
        friend reverse_iterator operator+(difference_type n, const reverse_iterator& one){
            return one._ite - n;
        }
        friend reverse_iterator operator-(difference_type n, const reverse_iterator& one){
            return one._ite + n;
        }
        reverse_iterator operator-(difference_type nbr) const{
            return this->_ite + nbr;
        }
        difference_type operator-(const reverse_iterator & one) const{
            return one._ite - this->_ite;
        }
    //     reverse_iterator<Iterator> operator-(difference_type n) const {return _pointer + n;} //a - n
	// difference_type operator-(const reverse_iterator& rhs) const {return rhs._pointer - _pointer;} //a - b
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
            if (this->_ite > bis._ite)
                return true;
            return false;
        }
        bool operator>=(const reverse_iterator bis) const{
            if (this->_ite >= bis._ite)
                return true;
            return false;
        }
        bool operator<=(const reverse_iterator bis) const{
            if (this->_ite <= bis._ite)
                return true;
            return false;
        }
        bool operator<(const reverse_iterator bis) const{
            if (this->_ite < bis._ite)
                return true;
            return false;
        }
        pointer get_ptr(void) const {
            return _ite;
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
    // return one.get_ptr() == two.get_ptr();
    return (one.base() == two.base());
}
template<typename it1, typename it2>
bool operator!=(const reverse_iterator<it1>& one, const reverse_iterator<it2>& two) {
    // return one.get_ptr() != two.get_ptr();
        return (one.base() != two.base());
}
template<typename it1, typename it2>
bool operator<(const reverse_iterator<it1>& one, const reverse_iterator<it2>& two) {
    return one.get_ptr() > two.get_ptr();}

template<typename it1, typename it2>
bool operator<=(const reverse_iterator<it1>& one, const reverse_iterator<it2>& two) {
    return one.get_ptr() >= two.get_ptr();
}
template<typename it1, typename it2>
bool operator>(const reverse_iterator<it1>& one, const reverse_iterator<it2>& two) {
    return one.get_ptr() < two.get_ptr();}

template<typename it1, typename it2>
bool operator>=(const reverse_iterator<it1>& one, const reverse_iterator<it2>& two) {
    return one.get_ptr() <= two.get_ptr();
}

}
#endif // !REVERSE_ITERATOR