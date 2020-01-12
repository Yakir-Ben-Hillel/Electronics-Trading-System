#ifndef __ARRAY_H
#define __ARRAY_H

#include <iostream>
using namespace std;

template <class T>
class Array
{
private:
    int logicSize, physicSize;
    char delimiter;
    T *array;

public:
    Array(int physicSize = 1, char delimiter = ' ') : delimiter(delimiter), physicSize(physicSize), logicSize(0)
    {
        array = new T[physicSize];
    }
    Array(const Array &other);
    ~Array() { delete[] array; }

    const Array &operator=(const Array &other);
    const Array &operator+=(const T &val);
    friend ostream &operator<<(ostream &out, const Array &arr)
    {
        for (const auto &x : arr)
            out << x << arr.delimiter;
        out << endl;
        return out;
    }
};

template <class T>
Array<T>::Array(const Array &other) : array(nullptr)
{
    *this = other;
}

template <class T>
const Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != other)
    {
        delete[] array;
        this->logicSize = other.logicSize;
        this->physicSize = other.physicSize;
        this->delimiter = other.delimiter;
        this->array = new T[this->physicSize];
        for (int i = 0; i < this->logicSize; i++)
        {
            this->array[i] = other.array[i];
        }
    }
    return *this;
}

template <class T>
const Array<T> &Array<T>::operator+=(const T &val)
{
    if (this->logicSize < this->physicSize)
    {
        this->array[this->logicSize++] = val;
    }
    else //we have to allocate new space for the new val
    {
        Array<T> temp(this->physicSize * 2, this->delimiter);
        for (int i = 0; i < this->logicSize; i++)
            temp += this->array[i];
        temp += val;
        *this = temp;
    }
    return *this;
}

#endif