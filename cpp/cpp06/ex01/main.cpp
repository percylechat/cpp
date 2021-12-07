#include <iostream>
#include <stdint.h>

struct Data
{
    int num;
};

uintptr_t	serialize(Data *p)
{
	return (reinterpret_cast<uintptr_t>(p));
}

Data	*deserialize(uintptr_t ser)
{
	return (reinterpret_cast<Data *>(ser));
}

int main()
{
    Data test;
    uintptr_t p;
    Data *address;

    std::cout << &test << std::endl;
    p = serialize(&test);
    std::cout << p << std::endl;
    address = deserialize(p);
    std::cout << address << std::endl;
}