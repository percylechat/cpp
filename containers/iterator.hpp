#ifndef ITERATOR_HPP
#define ITERATOR_HPP

// #include <iterator>
#include <memory>
// #include true/false type
// #include <type_traits>

namespace ft{

template <class Category, class T, class Distance = std::ptrdiff_t,
      class Pointer = T*, class Reference = T&>
    struct iterator {
        typedef Category  iterator_category;
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
};

template <class Iterator>
class iterator_traits
{
  public:
  	typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
};

template <class T> class iterator_traits<T*>
{
  public:
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
};

template <class T> class iterator_traits<const T*>
{
public:
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
};

template<bool B, class T = void> struct enable_if {};
 
template<class T> struct enable_if<true, T> {
typedef T type;
};

template <class T> struct is_integral{
	static const bool value_type = false;
	// type	either true_type or false_type
};

template<> struct is_integral<bool> { static const bool value_type = true; };
template<> struct is_integral<char> { static const bool value_type = true; };
template<> struct is_integral<char16_t> { static const bool value_type = true; };
template<> struct is_integral<char32_t> { static const bool value_type = true; };
template<> struct is_integral<wchar_t> { static const bool value_type = true; };
template<> struct is_integral<signed char> { static const bool value_type = true; };
template<> struct is_integral<short int> { static const bool value_type = true; };
template<> struct is_integral<int> { static const bool value_type = true; };
template<> struct is_integral<long int> { static const bool value_type = true; };
template<> struct is_integral<long long int> { static const bool value_type = true; };
template<> struct is_integral<unsigned char> { static const bool value_type = true; };
template<> struct is_integral<unsigned short int> { static const bool value_type = true; };
template<> struct is_integral<unsigned int> { static const bool value_type = true; };
template<> struct is_integral<unsigned long int> { static const bool value_type = true; };
template<> struct is_integral<unsigned long long int> { static const bool value_type = true; };

template<class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, 
           InputIt2 first2)
{
    for (; first1 != last1; ++first1, ++first2) {
        if (!(*first1 == *first2)) {
            return false;
        }
    }
    return true;
}

template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
{
  while (first1!=last1)
  {
    if (first2==last2 || *first2<*first1) return false;
    else if (*first1<*first2) return true;
    ++first1; ++first2;
  }
  return (first2!=last2);
}
}
#endif // !ITERATOR