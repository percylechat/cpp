#ifndef STACK_HPP
#define STACK_HPP

template<typename T> 

class ft_stack
{
    protected:
        T value_type;
        typedef Container container_type;
        typedef size size_type;
        typedef struct s_info t_info
        {
            T el;
            T *prev;
        };

    public:
        size {
            
        }
    Return size (public member function )
};

member type	definition	notes
value_type	The first template parameter (T)	Type of the elements
container_type	The second template parameter (Container)	Type of the underlying container
size_type	an unsigned integral type	usually the same as size_t

Member functions

(constructor)
    Construct stack (public member function )

empty
    Test whether container is empty (public member function )

size
    Return size (public member function )

top
    Access next element (public member function )

push
    Insert element (public member function )

pop
    Remove top element (public member function )

Non-member function overloads

relational operators
    Relational operators for stack (function )

#endif // !STACK_HPP
