#ifndef FT_ITERATOR_VEC
#define FT_ITERATOR_VEC

#include <memory> // allocator and ptrdiff_t
#include <iterator> //pour le trait?

//vector need a continuous iterator. It does everything.

// template <class T>
template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
class iterator_vec
{
    private:
    //     using iterator_category = std::forward_iterator_tag;
    // using difference_type   = std::ptrdiff_t;
    // using value_type        = int;
    // using pointer           = int*;  // or also value_type*
    // using reference         = int&;  // or also value_type&
        // typedef T         value_type;
        // typedef ptrdiff_t difference_type;
        // typedef *T pointer;
        // typedef &T reference;
        // typedef std::random_access_iterator_tag iterator_category;
    public:
        iterator_vec(){}
        iterator_vec(iterator_vec const one){
            if (this = &one)
                return (*one);
            
        }
        ~iterator_vec(){}

        // void advance(iterator_vec &i, difference_type n){
        //     i = i + n;
            //NO SECURE?
        }
        // distance (InputIterator first, InputIterator last);
};

#endif

advance
    Advance iterator (function template )

distance
    Return distance between iterators (function template )

Iterator generators:

back_inserter
    Construct back insert iterator (function template )

front_inserter
    Constructs front insert iterator (function template )

inserter
    Construct insert iterator (function template )

// iterators_traits, reverse_iterator, enable_if, is_integral, equal/lexicographical com-
// pare, std : :pair, std : :make_pair, doivent être réimplémenté.