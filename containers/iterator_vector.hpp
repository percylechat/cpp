#include <memory> // allocator and ptrdiff_t
#include "iterator.hpp"

template <class T> class iterator_vector{
    protected:
    // typedef iterator_traits<T> iterator_traits;

  public:
    // typedef typename iterator_traits::value_type value_type;
    // typedef typename iterator_traits::difference_type difference_type;
    // typedef typename iterator_traits::pointer pointer;
    // typedef typename iterator_traits::reference reference;
    // typedef typename std::random_access_iterator_tag iterator_category;
//    pointer _ite;
    // private:
        typedef T         value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
        pointer _ite;
    public:
////////////////////////////////////////////////////////////////////////
// CONSTRUCTEURS / DESTRUCTEUR
////////////////////////////////////////////////////////////////////////
        iterator_vector(){
            this->_ite = NULL;
        }
        iterator_vector(pointer p){
            this->_ite = p;
        }
        iterator_vector(iterator_vector const & one){
            this->_ite = one._ite;
        }
        iterator_vector& operator=(iterator_vector const & one) {
            this->_ite = one._ite;
            return *this;
        }
	    ~iterator_vector() {}
////////////////////////////////////////////////////////////////////////
// REF AND POINT
////////////////////////////////////////////////////////////////////////
        reference operator*(){
            return *this->_ite;
        }
        value_type* operator->(){
            return this->_ite;
        }
        value_type& operator[](int index) {
            return *(this->_ite + index);
        }
////////////////////////////////////////////////////////////////////////
// OPERATIONS
////////////////////////////////////////////////////////////////////////
        iterator_vector &operator++(){
            this->_ite++;
            return *this;
        }
        iterator_vector operator++(int){
            iterator_vector temp = *this;
            this->_ite++;
            return temp;
        }
        iterator_vector &operator--(){
            this->_ite--;
            return *this;
        }
        iterator_vector operator--(int){
            iterator_vector temp = *this;
            this->_ite--;
            return temp;
        }
        iterator_vector &operator+=(difference_type nbr){
            difference_type i = 0;
            while(i < nbr){
                this->_ite++;
                i++;
            }
            // this->_ite + nbr;
            return *this;
        }
        iterator_vector &operator-=(difference_type nbr){
            difference_type i = 0;
            while(i < nbr){
                this->_ite--;
                i++;
            }
            return *this;
        }
        iterator_vector operator+(difference_type nbr){
            return this->_ite + nbr;
        }
        iterator_vector operator-(difference_type nbr){
            return this->_ite - nbr;
        }
        difference_type operator-(const iterator_vector & one) const{
            return this->_ite - one._ite;
        }
////////////////////////////////////////////////////////////////////////
// COMPARE
////////////////////////////////////////////////////////////////////////
        bool operator!=(iterator_vector bis){
            if (this->_ite != bis._ite)
                return true;
            return false;
        }
        bool operator==(iterator_vector bis){
            if (this->_ite == bis._ite)
                return true;
            return false;
        }
        bool operator>(iterator_vector bis){
            if (this->_ite > bis._ite)
                return true;
            return false;
        }
        bool operator>=(iterator_vector bis){
            if (this->_ite >= bis._ite)
                return true;
            return false;
        }
        bool operator<=(iterator_vector bis){
            if (this->_ite <= bis._ite)
                return true;
            return false;
        }
        bool operator<(iterator_vector bis){
            if (this->_ite < bis._ite)
                return true;
            return false;
        }
};

template <class iterator_vector>
unsigned int ite_size(iterator_vector start, iterator_vector end){
    unsigned int i = 0;
    while (start != end){
        start++;
        i++;
    }
    return i;
}