#include <stdexcept>
	
template <typename T>
class Array
{
    private:
        T *content;
        int s;
    public:
        Array()
        {
            s = 0;
            content = new T[0];
        }
        Array(int n)
        {
            if (n < 0)
                throw std::out_of_range("Impossible Array");
            s = n;
            content = new T[n];
        }
        Array(const Array &one)
        {
            s = one.s;
            content = new T[s];
            int i = 0;
            while (i < s)
            {
                content[i] = one.content[i];
                i++;
            }
        }
        Array& operator=( const Array &one )
        {
            delete [] content;
            s = one.s;
            content = new T[s];
            int i = 0;
            while (i < s)
            {
                content[i] = one.content[i];
                i++;
            }
            return *this;
        }
        T& operator[]( int p )
        {
            if (p < 0 || p >= s)
                throw std::out_of_range("Not in Array");
            else
                return content[p];
        }
        ~Array() {delete [] content;}
        int size(){return s;}
};