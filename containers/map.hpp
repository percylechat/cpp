#include <functional>
#include "vector.hpp"
#include "pair.hpp"
#include "map_iterator.hpp"

namespace ft{

template <typename P>
struct N{
    P _content;
    N* l_child;
    N* r_child;
    N* mom;
    // bool go_last;
    N(P v, N* l, N* r, N* m): _content(v), l_child(l), r_child(r), mom(m){}//, go_last(false){}
    //     this->_content = v;
    //     this->l_child = l;
    //     this->r_child = r;
    //     this->mom = m;
    // }
};

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
class map{
    public:
////BASE
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
////STRUCT N
        typedef N<value_type>            n;
        typedef typename allocator_type::template rebind<n>::other n_allocator;
////BASE
        typedef map_iterator<value_type, n*> iterator;
        typedef map_iterator<value_type const, n*> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
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
        size_type _usage;
        n_allocator n_alloc;
        allocator_type _alloc;
        key_compare _keyc;
        n* _base;
        n* _end;
    public:
////////////////////////////////////////////////////////////////////////
// CONSTR/DESTR
////////////////////////////////////////////////////////////////////////
        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
            this->_usage = 0;
            this->_keyc = comp;
            this->_alloc = alloc;
            this->_end = new_n(value_type(key_type(), mapped_type()));
            this->_usage = 0;
        }
        template <class InputIterator>
        map(typename ft::enable_if<!ft::is_integral<InputIterator>::value_type, InputIterator>::type first,  InputIterator last, const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type()){
        // map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
        // const allocator_type& alloc = allocator_type()){
        //     this->_usage = 0;
        //     this->_keyc = comp;
        //     this->_alloc = alloc;
        //     this->_end = new_n(value_type(key_type(), mapped_type()));
        //     this->_usage = 0;
        //     // std::cout << first->first << std::endl;
        //     // first++;
        //     //             std::cout << first->first << std::endl;
        //     this->insert(first, last);
        // }
        // map(iterator first, iterator last, const key_compare& comp = key_compare(),
        // const allocator_type& alloc = allocator_type()){
            this->_keyc = comp;
            this->_alloc = alloc;
            this->_end = new_n(value_type(key_type(), mapped_type()));
            this->_end->l_child = NULL;
            this->_end->r_child = NULL;
            this->_usage = 0;
            // std::cout << first->first << std::endl;
            // first++;
            //             std::cout << first->first << std::endl;
            while (first != last){
                this->insert(*first);
                // std::cout << this->_base->_content.first << std::endl;
                first++;
            }
            // this->insert(first, last);
        }
        map(const map& x){
            *this = x;
            // this->_end = NULL;
        }
        map& operator=(const map& x){
            if (this->_usage != 0)
                this->clear();
            if (this->_end){
                            this->n_alloc.destroy(this->_end);
            this->n_alloc.deallocate(this->_end, 1);
            }
            this->_end = new_n(value_type(key_type(), mapped_type()));
            this->_end->l_child = NULL;
            this->_end->r_child = NULL;
            this->_usage = 0;
            this->insert(x.begin(), x.end());
            return *this;
        }
        ~map(){
            if (this->_usage != 0){
                while (this->_base->l_child != NULL){
                    std::cout << this->_base->l_child->_content.first << std::endl;
                    this->erase(iterator(this->_base->l_child));
                }
                while (this->_base->r_child != NULL && this->_base->r_child != this->_end){
                    std::cout << this->_base->r_child->_content.first << std::endl;
                    this->erase(iterator(this->_base->r_child));
                }
std::cout << "base " << this->_base->_content.first << std::endl;
                
                this->erase(iterator(this->_base));
            }
            this->n_alloc.destroy(this->_end);
            this->n_alloc.deallocate(this->_end, 1);
        }
////////////////////////////////////////////////////////////////////////
// ITERATOR
////////////////////////////////////////////////////////////////////////
        iterator begin(){
            if (this->_usage < 1)
                return iterator(this->_end);
            n* current = this->_base;
            while (current->l_child != NULL)
                current = current->l_child;
            // return map_iterator<value_type, n*>(current->_content, current);
            return iterator(current);
        }
        const_iterator begin() const{
            if (this->_usage < 1)
                return const_iterator(this->_end);
            n* current = this->_base;
            while (current->l_child != NULL)
                current = current->l_child;
            return const_iterator(current);
        }
        iterator end(){
            if (this->_usage < 1)
                return iterator(this->_end);
            n* current = this->_base;
            // while (current->r_child)
            //     current = current->r_child;
            while (current && current->r_child)
			    current = current->r_child;
		// return iterator(temp);
            return iterator(current);
        }
        const_iterator end() const{
            if (this->_usage < 1)
                // return const_iterator(this->_base);
                                return const_iterator(this->_end);
            // n* current = this->_base;
            // while (current->r_child)
            //     current = current->r_child;
            return const_iterator(this->_end);
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
            return (*((this->insert(value_type(k,mapped_type()))).first)).second;
        }
////////////////////////////////////////////////////////////////////////
// MODIFIERS
////////////////////////////////////////////////////////////////////////
        pair<iterator,bool> insert (const value_type& val){
            if (this->_usage == 0){
                // std::cout << "hello" << std::endl;
                this->_base = new_n(val);
                // this->_base->go_last = true;
                                // std::cout << "hello" << std::endl;
                this->_base->r_child = this->_end;
                this->_end->mom = this->_base;
                return pair<iterator, bool>(iterator(this->_base), true);
            }
            iterator buf1 = this->find(val.first);
            if (buf1 != this->end())
                return pair<iterator, bool>(buf1, false);
            n *current = this->_base;
            while ((this->_base->l_child != NULL && this->_keyc(val.first, this->_base->_content.first) == true ) ||
                (this->_base->r_child != NULL && this->_base->r_child != this->_end && this->_keyc(val.first, this->_base->_content.first) == false)){
                if (this->_keyc(val.first, this->_base->_content.first) == true && this->_base->l_child != NULL)
                    this->_base = this->_base->l_child;
                else if (this->_keyc(val.first, this->_base->_content.first) == false && this->_base->r_child != NULL)
                    this->_base = this->_base->r_child;
                else
                    break;
            }
            n *buf = this->_base;
            if (this->_keyc(val.first, this->_base->_content.first) == true){
                this->_base->l_child = new_n(val);
                this->_base = this->_base->l_child;
                this->_base->l_child = NULL;
                this->_base->r_child = NULL;
            }
            else{
                this->_base->r_child = new_n(val);
                this->_base = this->_base->r_child;
                this->_base->l_child = NULL;
                this->_base->r_child = NULL;
                this->gets_end(this->_base,current);
                // this->_base->r_child = this->_end;
            }
            this->_base->mom = buf;
            // std::cout << "ME: " << this->_base->_content.first << " MUM: " << buf->_content.first ;
            // if (buf->mom)
            //     std::cout << " GMA: " << buf->mom->_content.first ;
            // if (this->_base->r_child == this->_end)
            //     std::cout << "ENDIND" << std::endl;
            pair<iterator, bool> ret(iterator(this->_base), true);
            this->_base = current;
            return ret;
        }

        iterator insert (iterator position, const value_type& val){
            (void)position;
            return this->insert(val).first;
        }
        template <class InputIterator>
        void insert (typename ft::enable_if<!ft::is_integral<InputIterator>::value_type, InputIterator>::type first, InputIterator last){
        // void insert (InputIterator first, InputIterator last){
            // InputIterator buf = first;
            //             std::cout << "ok" << std::endl;
            // iterator it = first;
            // iterator ti = last;
                            // std::cout << this->_usage << std::endl;
            while (first != last){

                // key_type tmp = buf->first;
                // mapped_type temp = buf->second;
                // value_type temp = *buf;
                // this->insert(temp);
                // // this->insert(value_type(tmp, temp));
                // std::cout << "ok " << it->first << &it->mom << std::endl;
                // std::cout << first->first << std::endl;
                pair<iterator,bool>ret = this->insert(*first);
                                // std::cout << "hello" << std::endl;
                                // std::cout << this->_base->_content.first << std::endl;
                                // std::cout << this->_usage << std::endl;
                first++;
                // std::cout << first->first << std::endl;
                // this->insert(*first);
                // first++;
            }
            // std::cout << "ok" << std::endl;
        }

        iterator find (const key_type& k){
            if (this->_usage == 0)
                return this->end();
            if (this->_usage == 1 && (this->_keyc(this->_base->_content.first, k) == false)
            && (this->_keyc(k, this->_base->_content.first) == false))
                return iterator(this->_base);
            n* current = this->_base;
            while (1){ 
                if (this->_keyc(k, this->_base->_content.first) == false && this->_keyc(this->_base->_content.first, k) == false){
                    iterator ret(this->_base);
                    this->_base = current;
                    return ret;
                }
                else if (this->_keyc(k, this->_base->_content.first) == true){
                    if (this->_base->l_child != NULL)
                        this->_base = this->_base->l_child;
                    else{
                        // std::cout << "res " << this->_base->_content.first << std::endl;
                        this->_base = current;
                        return this->end();
                    }
                }
                else{
                    if (this->_base->r_child != NULL && this->_base->r_child != this->_end)
                        this->_base = this->_base->r_child;
                    else{
                        // std::cout << "res " << this->_base->_content.first << std::endl;
                        this->_base = current;
                        return this->end();
                    }
                }
            }
            this->_base = current;
            return this->end();
        }

        const_iterator find (const key_type& k) const{
            if (this->_usage == 0)
                return this->end();
            if (this->_usage == 1 && (this->_keyc(this->_base->_content.first, k) == false)
            && (this->_keyc(k, this->_base->_content.first) == false))
                return const_iterator(this->_base);
            n* current = this->_base;
            while (1){ 
                if (this->_keyc(k, current->_content.first) == false && this->_keyc(current->_content.first, k) == false){
                    return const_iterator(current);
                }
                else if (this->_keyc(k, current->_content.first) == true){
                    if (current->l_child != NULL)
                        current = current->l_child;
                    else{
                        // std::cout << "res " << current->_content.first << std::endl;
                        return this->end();
                    }
                }
                else{
                    if (current->r_child != NULL && current->r_child != this->_end)
                        current = current->r_child;
                    else{
                        // std::cout << "res " << current->_content.first << std::endl;
                        return this->end();
                    }
                }
            }
            return const_iterator(current);
        }

        size_type count (const key_type& k) const{
            const_iterator it = this->find(k);
            if (it == this->end())
                return 0;
            else
                return 1;
        }

        void clear(){ 
            while (this->_base->l_child != NULL)
                this->erase(iterator(this->_base->l_child));
            while (this->_base->r_child != NULL && this->_base->r_child != this->_end)
                this->erase(iterator(this->_base->r_child));
            this->erase(iterator(this->_base));
            // this->n_alloc.destroy(this->_end);
            // this->n_alloc.deallocate(this->_end, 1);
            this->_usage = 0;
        }
        void erase (iterator position){
            if (position == this->end())
                return;
            n *pos = this->find(position);
            this->_usage--;
            std::cout << "key " << pos->_content.first << " base " << this->_base->_content.first << std::endl;
            if (pos->l_child == NULL && pos->r_child == NULL)
            {
                std::cout << "ping in 0" << pos->_content.first << std::endl;
                if (pos->mom != NULL){
                    n* buf = pos->mom;
                    if (buf->l_child != NULL && buf->l_child == pos)
                        buf->l_child = NULL;
                    else if (buf->r_child && buf->r_child == pos)
                        buf->r_child = NULL;
                }
                this->n_alloc.destroy(pos);
                this->n_alloc.deallocate(pos, 1);
            }
            else if (pos->l_child != NULL && pos->r_child != NULL && pos->r_child != this->_end)
            {
                std::cout << "ping in 2" << pos->_content.first << std::endl;
                n *temp = pos->r_child;
                n *temp1 = pos->l_child;
                if (pos->mom != NULL){
                    n* buf = pos->mom;
                    if (buf->l_child && buf->l_child == pos)
                        buf->l_child = temp;
                    else
                        buf->r_child = temp;
                    temp->mom = buf;
                }
                else
                    this->_base = temp;
                while (temp->l_child != NULL)
                    temp = temp->l_child;
                temp->l_child = temp1;
                this->n_alloc.destroy(pos);
                this->n_alloc.deallocate(pos, 1);

            }
            else if (pos->r_child == this->_end && pos->l_child == NULL){
                std::cout << "ping in 3" << pos->_content.first << std::endl;
                if (pos->mom != NULL){
                    n* buf = pos->mom;
                    buf->r_child = this->_end;
                    this->_end->mom = buf;
                }
                this->n_alloc.destroy(pos);
                this->n_alloc.deallocate(pos, 1);
            }
            else if (pos->r_child == this->_end && pos->l_child != NULL){
                std::cout << "ping in 4" << pos->_content.first << std::endl;
                if (pos->mom != NULL){
                    n* buf = pos->mom;
                    buf->r_child = pos->l_child;
                    pos->l_child->r_child = this->_end;
                    pos->l_child->mom = buf;
                    this->_end->mom = pos->l_child;
                }
                this->n_alloc.destroy(pos);
                this->n_alloc.deallocate(pos, 1);
            }
            else if ((pos->r_child != NULL && pos->r_child != this->_end) || pos->l_child != NULL){
                std::cout << "ping in 1" << pos->_content.first << std::endl;
                n *temp;
                if (pos->r_child != NULL)
                    temp = pos->r_child;
                else
                    temp = pos->l_child;
                if (pos->mom != NULL){
                    n* buf = pos->mom;
                    if (buf->l_child != NULL && buf->l_child == pos)
                        buf->l_child = temp;
                    else
                        buf->r_child = temp;
                    temp->mom = buf;
                }
                else{
                    this->_base = temp;
                    temp->mom = NULL;
                }
                this->n_alloc.destroy(pos);
                this->n_alloc.deallocate(pos, 1);
            }
            else{
            }
        }
        size_type erase (const key_type& k){
            iterator buf = this->find(k);
            if (buf == this->end())
                return 0;
            else
                this->erase(buf);
            return 1;
        }
        void erase (iterator first, iterator last){
            iterator buf = first;
            while (first != last){
                // std::cout << first->first << std::endl;
                first++;
                buf = first;
                first--;
                this->erase(this->find(first->first));
                // std::cout << "ok" << std::endl;
                first = buf;
            }
        }
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
            n* d = this->_base;
            this->_base = x._base;
            x._base = d;
            n* e = this->_end;
            this->_end = x._end;
            x._end = e;
        }
////////////////////////////////////////////////////////////////////////
// OBSERVERS
////////////////////////////////////////////////////////////////////////
        key_compare key_comp() const{
            return this->_keyc;
        }

        value_compare value_comp() const{
            return value_compare(key_compare());
        }
////////////////////////////////////////////////////////////////////////
// ALLOCATOR
////////////////////////////////////////////////////////////////////////
        allocator_type get_allocator() const{
            return this->_alloc;
        }

    private:
        n* new_n(const value_type& val){
		    n *buf = this->n_alloc.allocate(1);
		    this->n_alloc.construct(buf, n(val, NULL, NULL, NULL));
            this->_usage++;
            return buf;
        }
        n* find(iterator it){
            if (this->_usage == 0)
                return this->_end;
            if (this->_usage == 1 && (this->_keyc(this->_base->_content.first, it->first) == false)
            && (this->_keyc(it->first, this->_base->_content.first) == false))
                return this->_base;
            n* current = this->_base;
            while (1){ 
                if (this->_keyc(it->first, this->_base->_content.first) == false && this->_keyc(this->_base->_content.first, it->first) == false){
                    n* ret = this->_base;
                    this->_base = current;
                    return ret;
                }
                else if (this->_keyc(it->first, this->_base->_content.first) == true){
                    if (this->_base->l_child != NULL)
                        this->_base = this->_base->l_child;
                    else{
                        // std::cout << "res " << this->_base->_content.first << std::endl;
                        this->_base = current;
                        return this->_end;
                    }
                }
                else{
                    if (this->_base->r_child != NULL && this->_base->r_child != this->_end)
                        this->_base = this->_base->r_child;
                    else{
                        // std::cout << "res " << this->_base->_content.first << std::endl;
                        this->_base = current;
                        return this->_end;
                    }
                }
            }
            n* ret = this->_base;
            this->_base = current;
            return ret;
            // if (this->_usage == 0)
            //     return this->_end;
            // if (this->_usage == 1 && (this->_keyc(this->_base->_content.first, it->first) == false)
            // && (this->_keyc(it->first, this->_base->_content.first) == false))
            //     return this->_base;
            // std::cout << "test" << it->first << std::endl;
            // n* current = this->_base;
            // while (this->_base->l_child != NULL || (this->_base->r_child != NULL && this->_base->r_child != this->_end)){
            //     if (this->_base->l_child != NULL && this->_keyc(it->first, this->_base->_content.first) == true)
            //         this->_base = this->_base->l_child;
            //     else if (this->_base->r_child != NULL && this->_base->r_child != this->_end && this->_keyc(it->first, this->_base->_content.first) == false){
            //         if (this->_keyc(this->_base->_content.first, it->first) == false){
            //             n* ret = this->_base;
            //             this->_base = current;
            //             std::cout << "test2" << ret->_content.first << std::endl;
            //             return ret;
            //         }
            //         this->_base = this->_base->r_child;
            //     }
            //     else
            //         break;
            // }
            // this->_base = current;
            // return this->_end;
        }
        void gets_end(n* current, n* wit){
            n* temp =  wit;
            while (temp->r_child != NULL && temp->r_child != this->_end)
                temp = temp->r_child;
            if (temp == current){
                current->r_child = this->_end;
                this->_end->mom = current;
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