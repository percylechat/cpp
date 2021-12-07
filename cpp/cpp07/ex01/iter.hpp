#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void    iter(T *array, int l, void (*func)(T &i))
{
    int j = 0;
    while (j < l)
    {
        func(array[j]);
        j++;
    }
}

// template <typename T>
// void    iter(T *array, int l, void (*func)(T const &i))
// {
//     int j = 0;
//     while (j < l)
//     {
//         func(array[j]);
//         j++;
//     }
// }

#endif