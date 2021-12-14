#include <memory> // allocator and ptrdiff_t

template <class T>
class iterator_vector{
    private:
        typedef T         value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
        pointer _ite;
    public:
        iterator_vector(pointer p){
            this->_ite = p;
        }
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
        reference operator*(){
            return *this->_ite;
        }
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
};