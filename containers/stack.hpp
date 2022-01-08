#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft{

template <class T, class Container = ft::vector<T> > class stack
{
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef typename container_type::size_type size_type;
    private:
        Container _content;
    public:
        explicit stack (const container_type& ctnr = container_type()) : _content(ctnr) {}
        ~stack(void){}
        bool empty() const {
            return this->_content.empty();
        }
        size_type size() const {
            return this->_content.size();
        }
        value_type& top() {
            return this->_content.back();
        }
        const value_type& top() const {
            return this->_content.back();
        }
        void push (const value_type& val) {
            this->_content.push_back(val);
        }
        void pop() { 
            this->_content.pop_back();
        }
        template <class R, class Cont>
        friend bool operator== (const stack<R, Cont> &one, const stack<R, Cont> &two){ 
            return one._content == two._content;
        }
        template <class R, class Cont>
        friend bool operator!= (const stack<R, Cont> &one, const stack<R, Cont> &two){
            return one._content != two._content;
        }
        template <class R, class Cont>
        friend bool operator< (const stack<R, Cont> &one, const stack<R, Cont> &two){
            return one._content < two._content;
        }
        template <class R, class Cont>
        friend bool operator<= (const stack<R, Cont> &one, const stack<T, Cont> &two){
             return one._content <= two._content;
        }
        template <class R, class Cont>
        friend bool operator> (const stack<R, Cont> &one, const stack<T, Cont> &two){
             return one._content > two._content; 
        }
        template <class R, class Cont>
        friend bool operator>= (const stack<R, Cont> &one, const stack<T, Cont> &two){
             return one._content >= two._content;
        }
};

}
#endif
