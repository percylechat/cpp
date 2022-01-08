#ifndef FT_VECTOR
#define FT_VECTOR

#include <memory> //allocator
#include <iterator>

// typename <template T>
template < class T, class Alloc = std::allocator<T> > class ft_vector{
    private:
        typedef T value_type;
        typedef Alloc allocator_type;
        // typedef &value_type reference;
        typedef typename allocator_type::reference reference;
        // typedef const &value_type const_reference;
        typedef typename allocator_type::const_reference const_reference;
        // typedef *value_type pointer;
        typedef typename allocator_type::pointer pointer;
        // typedef const *value_type const_pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        // typedef size_t size_type;
        typedef typename allocator_type::size_type size_type;
        // typedef ptrdiff_t difference_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef vector_iterator<value_type> iterator;
        typedef vector_iterator<value_type const> const_iterator;
        size_type capacity;
        unsigned int usage;

// reverse_iterator	reverse_iterator<iterator>	
// const_reverse_iterator	reverse_iterator<const_iterator>	

    public:
        explicit ft_vector(void){
            const allocator_type& alloc = allocator_type();
            this->capacity = 0;
            this->usage = 0;
        } //default
        explicit ft_vector(size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()){
            this->capacity = n;
            this->usage = n;
            this->pointer = this->alloc.allocate(n);
            int i = 0;
            while (i < n)
            {
                &iterator = val;
                i++;
                iterator++;
            }
        }//fill
// range (3)	
// template <class InputIterator>
//          ft_vector (InputIterator first, InputIterator last,
//                  const allocator_type& alloc = allocator_type());
        ft_vector(const ft_vector& x){
            this->capacity = x->capacity;
            this->usage = x->usage;
            this->pointer = x->pointer;
            int i = 0;
            while (i < this->capacity)
            {
                this->pointer[i] = x->pointer[i];
                i++;
            }
        }//copy
        ~ft_vector(){
            this->alloc.deallocate(this->pointer, this->capacity);
        } //destructeur


    void push_back(const value_type& val){
        if (this->capacity == this->usage)
        {
            typename allocator_type::pointer tmp;
            tmp.allocate((this->capacity + 1));
            int i = 0;
            while(i < this->capacity)
            {
                tmp[i] = this->pointer[i];
                i++;
            }
            tmp[i] = val;
            this->alloc.deallocate(this->pointer, this->capacity)
            this->pointer = tmp;
            this->capacity++;
            this->usage++;
        }
        else
        {
            usage++;
            this->pointer[this->usage] = val;
        }
    }
    // push_back
        // Add element at the end (public member function )

};

#endif // !FT_VECTOR



// Vector
// Vectors are sequence containers representing arrays that can change in size.
// Just like arrays, vectors use contiguous storage locations for their elements,
// which means that their elements can also be accessed using offsets on regular pointers to its elements,
// and just as efficiently as in arrays. But unlike arrays, their size can change dynamically,
// with their storage being handled automatically by the container.

// Internally, vectors use a dynamically allocated array to store their elements.
// This array may need to be reallocated in order to grow in size when new elements are inserted,
// which implies allocating a new array and moving all elements to it.
// This is a relatively expensive task in terms of processing time, and thus,
// vectors do not reallocate each time an element is added to the container.

// Instead, vector containers may allocate some extra storage to accommodate for possible growth,
// and thus the container may have an actual capacity greater than the storage strictly needed to contain its elements
// (i.e., its size). Libraries can implement different strategies for growth to balance between memory usage and
// reallocations, but in any case, reallocations should only happen at logarithmically growing intervals of size
// so that the insertion of individual elements at the end of the vector can be provided with amortized constant time
// complexity (see push_back).

// Therefore, compared to arrays, vectors consume more memory in exchange for the ability to manage storage and
// grow dynamically in an efficient way.

// Compared to the other dynamic sequence containers (deques, lists and forward_lists), vectors are very efficient
// accessing its elements (just like arrays) and relatively efficient adding or removing elements from its end.
// For operations that involve inserting or removing elements at positions other than the end, they perform worse than
// the others, and have less consistent iterators and references than lists and forward_lists.

// Container properties

// Sequence
//     Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed
//     by their position in this sequence.
// Dynamic array
//     Allows direct access to any element in the sequence, even through pointer arithmetics, and provides relatively
//     fast addition/removal of elements at the end of the sequence.
// Allocator-aware
//     The container uses an allocator object to dynamically handle its storage needs.


// Template parameters

// T
//     Type of the elements.
//     Only if T is guaranteed to not throw while moving, implementations can optimize to move elements instead of
//     copying them during reallocations.
//     Aliased as member type vector::value_type.
// Alloc
//     Type of the allocator object used to define the storage allocation model. By default, the allocator class
//     template is used, which defines the simplest memory allocation model and is value-independent.
//     Aliased as member type vector::allocator_type.

// Member functions

// (constructor)
//     Construct vector (public member function )

// (destructor)
//     Vector destructor (public member function )

// operator=
//     Assign content (public member function )


// Iterators:

// begin
//     Return iterator to beginning (public member function )

// end
//     Return iterator to end (public member function )

// rbegin
//     Return reverse iterator to reverse beginning (public member function )

// rend
//     Return reverse iterator to reverse end (public member function )

// Capacity:

// size
//     Return size (public member function )

// max_size
//     Return maximum size (public member function )

// resize
//     Change size (public member function )

// capacity
//     Return size of allocated storage capacity (public member function )

// empty
//     Test whether vector is empty (public member function )

// reserve
//     Request a change in capacity (public member function )

// Element access:

// operator[]
//     Access element (public member function )

// at
//     Access element (public member function )

// front
//     Access first element (public member function )

// back
//     Access last element (public member function )


// Modifiers:

// assign
//     Assign vector content (public member function )

// pop_back
//     Delete last element (public member function )

// insert
//     Insert elements (public member function )

// erase
//     Erase elements (public member function )

// swap
//     Swap content (public member function )

// clear
//     Clear content (public member function )


// Allocator:

// get_allocator
//     Get allocator (public member function )


// Non-member function overloads

// relational operators
//     Relational operators for vector (function template )

// swap
//     Exchange contents of vectors (function template )

