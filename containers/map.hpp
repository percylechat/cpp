#include <functional>
#include "vector.hpp"
#include "pair.hpp"
#include "map_iterator.hpp"

namespace ft{

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
class map{
    public:
        typedef Key key_type;
        typedef T mapped_type;	
        typedef ft::pair<const key_type,mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename allocator_type::size_type                    size_type;
        typedef typename allocator_type::difference_type              difference_type;
        typedef map_iterator<value_type> iterator;
        typedef map_iterator<value_type const> const_iterator;
        // typedef ft::reverse_iterator<iterator> reverse_iterator;
        // typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        class value_compare {
            friend class map;
            protected:
                Compare comp;
                value_compare (Compare c) : comp(c) {}
            public:
                typedef bool result_type;
                typedef value_type first_argument_type;
                typedef value_type second_argument_type;
                bool operator() (const value_type& x, const value_type& y) const {
                    return comp(x.first, y.first);
                }
        };
    protected:
        struct n{
            value_type _current;
            pointer l_child;
            pointer r_child;
            pointer mom;
        };
        size_type _usage;
        allocator_type _alloc;
        key_compare _keyc;
        pointer _base;
    public:
////////////////////////////////////////////////////////////////////////
// CONSTR/DESTR
////////////////////////////////////////////////////////////////////////
        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
            this->_usage = 0;
            this->_keyc = comp;
            this->_alloc = alloc;
        }
        template <class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type()){
            this->_usage = 0;
            this->_keyc = comp;
            this->_alloc = alloc;
            this->insert(first, last);
        }
        map(const map& x){
            *this = x;
        }
        map& operator=(const map& x){
            this->clear();
            this->insert(x.begin(), x.end());
            return *this;
        }
        ~map(){
            this->clear_all(this->_base);
        }
////////////////////////////////////////////////////////////////////////
// ITERATOR
////////////////////////////////////////////////////////////////////////
        iterator begin(){
            if (this->_usage <= 1)
                return iterator(this->_base);
            pointer buf = l_child;
            while (l_child)
                buf = l_child;
            return iterator(buf);
        }
        const_iterator begin() const{
            if (this->_usage <= 1)
                return const_iterator(this->_base);
            pointer buf = l_child;
            while (l_child)
                buf = l_child;
            return const_iterator(buf);
        }
        iterator end(){
            if (this->_usage <= 1)
                return iterator(this->_base);
            pointer buf = r_child;
            while (r_child)
                buf = r_child;
            return iterator(buf);
        }
        const_iterator end() const{
            if (this->_usage <= 1)
                return const_iterator(this->_base);
            pointer buf = r_child;
            while (r_child)
                buf = r_child;
            return const_iterator(buf);
        }
        // reverse_iterator rbegin(){
        //     if (this->_usage <= 1)
        //         return reverse_iterator(this->_base);
            // pointer buf = r_child;
            // while (r_child)
            //     buf = r_child;
        //     return reverse_iterator(buf);
        // const_reverse_iterator rbegin() const{
        //     if (this->_usage <= 1)
        //         return const_reverse_iterator(this->_base);
        //                 pointer buf = r_child;
            // while (r_child)
            //     buf = r_child;
        //     return const_reverse_iterator(buf);
        // }
        // reverse_iterator rend(){
        //     if (this->_usage <= 1)
        //         return reverse_iterator(this->_base);
        //     pointer buf = l_child;
            // while (l_child)
            //     buf = l_child;
        //     return reverse_iterator(buf);
        // }
        // const_reverse_iterator rend() const{
        //     if (this->_usage <= 1)
        //         return const_reverse_iterator(this->_base);
        //     pointer buf = l_child;
            // while (l_child)
                // buf = l_child;
        //     return const_reverse_iterator(buf);
        // }
////////////////////////////////////////////////////////////////////////
// CAPACITY
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
////////////////////////////////////////////////////////////////////////
// ELT_ACCESS
////////////////////////////////////////////////////////////////////////
        mapped_type& operator[] (const key_type& k){
            return (*((this->insert(make_pair(k,mapped_type()))).first)).second;
        }
////////////////////////////////////////////////////////////////////////
// MODIFIERS
////////////////////////////////////////////////////////////////////////
        pair<iterator,bool> insert (const value_type& val){
            if (this->_usage == 0){
                this->_base = new_n(val);
                return pair<iterator, bool>(iterator(this->_base), true);
            }
            iterator buf = this->find(val.first);
            if (buf != this->end())
                return pair<iterator, bool>(buf, false);
            pointer current = this->_base;
            while ((!l_child && this->_keyc(val.first, (*current).first) == true ) ||
                (!r_child && this->_keyc(val.first, (*current).first) == false)){
                if (this->_keyc(val.first, (*current).first) == true)
                    current = l_child;
                else
                    current = r_child;
            }
            mom = current;
            if (!l_child){
                l_child = new_n(val);
                current = l_child;
            }
            else{
                r_child = new_n(val);
                current = r_child;
            }
            return pair<iterator, bool>(iterator(current), true);
        }

        // iterator insert (iterator position, const value_type& val);
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last){
            InputIterator buf = first;
            while (buf != last){
                this->insert(*buf);
                buf++;
            }
        }

        iterator find (const key_type& k){
            if (this->_usage == 0)
                return this->end();
            pointer current = this->_base;
            while (!l_child && !r_child){
                if (this->_keyc(k, (*current).first) == true)
                    current = l_child;
                else{
                    if (this->_keyc((*current).first, k) == false)
                        return iterator(current);
                    current = r_child;
                }
            }
            return this->end();
        }

        // const_iterator find (const key_type& k) const;

        void clear(){
            this->clear_all(this->_base);
        }
        // void erase (iterator position);
        // size_type erase (const key_type& k);
        // void erase (iterator first, iterator last);
        void swap(map &x){
            allocator_type buf = this->_alloc;
            this->_alloc = x._alloc;
            x._alloc = buf;
            size_type b = this->_usage;
            this->_usage = x._usage;
            x._usage = b;
            key_compare c = this->_keyc;
            this->_keyc = x._keyc;
            x._keyc =c;
            pointer d = this->_base;
            this->_base = x._base;
            x._base = d;
        }
////////////////////////////////////////////////////////////////////////
// OBSERVERS
////////////////////////////////////////////////////////////////////////
        key_compare key_comp() const{
            return this->_keyc;
        }
        // value_compare value_comp() const{
        //     return key_comp;
        // }
////////////////////////////////////////////////////////////////////////
// ALLOCATOR
////////////////////////////////////////////////////////////////////////
        allocator_type get_allocator() const{
            return this->_alloc;
        }

    private:
        pointer new_n(const value_type& val){
            pointer buf = this->_alloc.allocate(1);
            this->_alloc.construct(buf, val);
            this->_usage++;
            return buf;
        }
        void clear_all(pointer current) {
            if (current) {
                clear_all(l_child);
                clear_all(r_child);
                this->_usage--;
                this->_alloc.destroy(current);
                this->_alloc.deallocate(current, 1);
                if (current == this->_base)
                    this->_base = NULL;
            }
        }
};

template <class Key, class T, class Compare, class Alloc>
bool operator== (const map<Key, T, Compare, Alloc>& one, const map<Key, T, Compare, Alloc>& two) {
	if (one.size() != two.size())
		return false;
	return equal(one.begin(), one.end(), two.begin());
}
template <class Key, class T, class Compare, class Alloc>
bool operator!= (const map<Key, T, Compare, Alloc>& one, const map<Key, T, Compare, Alloc>& two) {
    return !(one == two);
}
template <class Key, class T, class Compare, class Alloc>
bool operator< (const map<Key, T, Compare, Alloc>& one, const map<Key, T, Compare, Alloc>& two) {
	return lexicographical_compare(one.begin(), one.end(), two.begin(), two.end());
}
template <class Key, class T, class Compare, class Alloc>
bool operator<= (const map<Key, T, Compare, Alloc>& one, const map<Key, T, Compare, Alloc>& two) {
    return (one < two || one == two);
}
template <class Key, class T, class Compare, class Alloc>
bool operator> (const map<Key, T, Compare, Alloc>& one, const map<Key, T, Compare, Alloc>& two) {
    return (two < one);
}
template <class Key, class T, class Compare, class Alloc>
bool operator>= (const map<Key, T, Compare, Alloc>& one, const map<Key, T, Compare, Alloc>& two) {
    return (one > two || one == two);
}
template <class Key, class T, class Compare, class Alloc>
void swap (map<Key, T, Compare, Alloc>& one, map<Key, T, Compare, Alloc>& two) {
    one.swap(two);
}

};