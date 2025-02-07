#include "Array.hpp"

Array::Array() : _data(new T[0]), _size(0)
{}

Array::Array(unsigned int n) : _data(new T[n]), _size(n)
{}

Array::Array(const Array &src) : _data(new T[src._size]), _size(src._size)
{
    for (unsigned int i = 0; i < _size; i++)
        _data[i] = src._data[i];
}

Array::~Array()
{ delete[] _data; }

Array   &Array::operator=(const Array &src)
{
    if (this != &src)
    {
        delete[] _data;
        _size = src._size;
        _data = new T(_size);
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = src._data;
    }
    return (*this);
}

T   &Array::operator[](unsigned int index) const
{
    if (index >= _size)
        throw (std::out_of_range("Index is out of bounds!"));
    return (_data[index]);
}

unsigned int    Array::size() const
{ return (_size); }