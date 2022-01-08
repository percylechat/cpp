#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

// #include "map.hpp"

namespace ft {

template<typename T>
class map_iterator{
        typedef T         value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
    protected:
        pointer _ite;
    public:
        map_iterator(){
            this->_ite = NULL;
        }
        map_iterator(pointer p){
            this->_ite = p;
        }
        map_iterator(map_iterator const & one){
            this->_ite = one._ite;
        }
        map_iterator& operator=(map_iterator const & one) {
            this->_ite = one._ite;
            return *this;
        }
	    ~map_iterator() {}
        operator map_iterator<value_type const>() const {
            return map_iterator<value_type const>(this->_ite);
        }

        reference operator*(){
            return *this->_ite;
        }
        value_type* operator->(){
            return this->_ite;
        }

        map_iterator &operator++(){
            
            // this->_ite++;
            return *this;
        }

        bool operator!=(const map_iterator bis) const{
            if (this->_ite != bis._ite)
                return true;
            return false;
        }
        bool operator==(const map_iterator bis) const{
            if (this->_ite == bis._ite)
                return true;
            return false;
        }
        bool operator>(const map_iterator bis) const{
            if (this->_ite > bis._ite)
                return true;
            return false;
        }
        bool operator>=(const map_iterator bis) const{
            if (this->_ite >= bis._ite)
                return true;
            return false;
        }
        bool operator<=(const map_iterator bis) const{
            if (this->_ite <= bis._ite)
                return true;
            return false;
        }
        bool operator<(const map_iterator bis) const{
            if (this->_ite < bis._ite)
                return true;
            return false;
        }

};


};
#endif