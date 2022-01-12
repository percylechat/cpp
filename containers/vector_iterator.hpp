#include <memory> // allocator and ptrdiff_t
#include "iterator.hpp"

template <class T> class vector_iterator{
    public:
        typedef T         value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
    protected:
        pointer _ite;
    public:
////////////////////////////////////////////////////////////////////////
// CONSTRUCTEURS / DESTRUCTEUR
////////////////////////////////////////////////////////////////////////
        vector_iterator(){
            this->_ite = NULL;
        }
        vector_iterator(pointer p){
            this->_ite = p;
        }
        vector_iterator(vector_iterator const & one){
            this->_ite = one._ite;
        }
        vector_iterator& operator=(vector_iterator const & one) {
            this->_ite = one._ite;
            return *this;
        }
	    ~vector_iterator() {}
        operator vector_iterator<value_type const>() const {
            return vector_iterator<value_type const>(this->_ite);
        }
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
        vector_iterator &operator++(){
            this->_ite++;
            return *this;
        }
        vector_iterator operator++(int){
            vector_iterator temp = *this;
            this->_ite++;
            return temp;
        }
        vector_iterator &operator--(){
            this->_ite--;
            return *this;
        }
        vector_iterator operator--(int){
            vector_iterator temp = *this;
            this->_ite--;
            return temp;
        }
        vector_iterator &operator+=(difference_type nbr){
            difference_type i = 0;
            while(i < nbr){
                this->_ite++;
                i++;
            }
            return *this;
        }
        vector_iterator &operator-=(difference_type nbr){
            difference_type i = 0;
            while(i < nbr){
                this->_ite--;
                i++;
            }
            return *this;
        }
        vector_iterator operator+(difference_type nbr)const{
            return this->_ite + nbr;
        }
        vector_iterator operator-(difference_type nbr)const{
            return this->_ite - nbr;
        }
        difference_type operator-(const vector_iterator & one) const{
            return this->_ite - one._ite;
        }
        difference_type operator+(const vector_iterator & one) const{
            return this->_ite + one._ite;
        }
        friend vector_iterator operator+(difference_type n, const vector_iterator& one){
            return n + one._ite;
        }
        friend vector_iterator operator-(difference_type n, const vector_iterator& one){
            return n - one._ite;
        }
////////////////////////////////////////////////////////////////////////
// COMPARE
////////////////////////////////////////////////////////////////////////
        bool operator!=(const vector_iterator bis) const{
            if (this->_ite != bis._ite)
                return true;
            return false;
        }
        bool operator==(const vector_iterator bis) const{
            if (this->_ite == bis._ite)
                return true;
            return false;
        }
        bool operator>(const vector_iterator bis) const{
            if (this->_ite > bis._ite)
                return true;
            return false;
        }
        bool operator>=(const vector_iterator bis) const{
            if (this->_ite >= bis._ite)
                return true;
            return false;
        }
        bool operator<=(const vector_iterator bis) const{
            if (this->_ite <= bis._ite)
                return true;
            return false;
        }
        bool operator<(const vector_iterator bis) const{
            if (this->_ite < bis._ite)
                return true;
            return false;
        }
        pointer get_ptr(void) const {
            return _ite;
        }
};

template<typename it1, typename it2>
bool operator==(const vector_iterator<it1>& one, const vector_iterator<it2>& two) {
    return one.get_ptr() == two.get_ptr();
}
template<typename it1, typename it2>
bool operator!=(const vector_iterator<it1>& one, const vector_iterator<it2>& two) {
    return one.get_ptr() != two.get_ptr();
}
template<typename it1, typename it2>
bool operator<(const vector_iterator<it1>& one, const vector_iterator<it2>& two) {
    return one.get_ptr() < two.get_ptr();}

template<typename it1, typename it2>
bool operator<=(const vector_iterator<it1>& one, const vector_iterator<it2>& two) {
    return one.get_ptr() <= two.get_ptr();
}
template<typename it1, typename it2>
bool operator>(const vector_iterator<it1>& one, const vector_iterator<it2>& two) {
    return one.get_ptr() > two.get_ptr();}

template<typename it1, typename it2>
bool operator>=(const vector_iterator<it1>& one, const vector_iterator<it2>& two) {
    return one.get_ptr() >= two.get_ptr();
}

template <class vector_iterator>
unsigned int ite_size(vector_iterator start, vector_iterator end){
    unsigned int i = 0;
    while (start != end){
        start++;
        i++;
    }
    return i;
}