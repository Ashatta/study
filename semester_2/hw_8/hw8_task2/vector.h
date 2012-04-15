#pragma once
#include <iostream>

template<class T, int size>
class Vector
{
public:
    /// Copy constructor of class Vector<T, size>
    Vector(const Vector<T, size> &copy);
    /** Constructor that initialize vector with
     *  an array v of length s
     */
    Vector(const T* v, int s);
    /** Constructor that initialize vector with
     *  scalar. Result is (scalar, 0, ..., 0)
     */
    Vector(const T &scalar = 0);
    ~Vector() {}
    
    /// Method isNull returns true if the vector is null
    bool isNull() const;
    /// Method add returns the result of addition of *this and second
    Vector<T, size> add(const Vector<T, size> &second) const;
    /** Method add returns the result of subtraction 
     *  of second from *this
     */
    Vector<T, size> subtract(const Vector<T, size> &second) const;
    /// Method scalarMultiply returns a dot-product of two vectors
    T scalarMultiply(const Vector<T, size> &second) const;
    /** Method multiply returns a result of multiplication of
     *  vector and scalar
     */
    Vector<T, size> multiply(const T &scalar) const;
    /// Method print prints the vector in a stream out
    void print(std::ostream &out) const;

private:
    T vector[size]; ///< Array that stores coordinates of vector
    
friend Vector<T, size> operator+ 
    (const Vector<T, size> &first, const Vector<T, size> &second)
{ 
    return first.add(second); 
}
friend Vector<T, size> operator- 
    (const Vector<T, size> &first, const Vector<T, size> &second)
{ 
    return first.subtract(second); 
}
friend Vector<T, size> operator* 
    (const T &scalar, const Vector<T, size> &vector)
{ 
    return vector.multiply(scalar); 
}

};

template<class T, int size>
Vector<T, size>::Vector(const Vector<T, size> &copy)
{
    for (int i = 0; i < size; i++)
        vector[i] = copy.vector[i];
}

template<class T, int size>
Vector<T, size>::Vector(const T &scalar)
{
    vector[0] = scalar;
    for (int i = 1; i < size; i++)
        vector[i] = 0;
}

template<class T, int size>
Vector<T, size>::Vector(const T* v, int s)
{
    for (int i = 0; i < s && i < size; i++)
        vector[i] = v[i];
    if (s < size)
        for (int j = s; j < size; j++)
            vector[j] = 0;
}

template<class T, int size>
Vector<T, size> Vector<T, size>::add(const Vector<T, size> &second) const
{
    Vector<T, size> result;
    for (int i = 0; i < size; i++)
        result.vector[i] = vector[i] + second.vector[i];
    return result;
}

template<class T, int size>
Vector<T, size> Vector<T, size>::subtract(const Vector<T, size> &second) const
{
    Vector<T, size> result;
    for (int i = 0; i < size; i++)
        result.vector[i] = vector[i] - second.vector[i];
    return result;
}

template<class T, int size>
T Vector<T, size>::scalarMultiply(const Vector<T, size> &second) const
{
    T result = 0;
    for (int i = 0; i < size; i++)
        result = result + vector[i] * second.vector[i];
    return result;
}

template<class T, int size>
Vector<T, size> Vector<T, size>::multiply(const T &scalar) const
{
    Vector<T, size> result;
    for (int i = 0; i < size; i++)
        result.vector[i] = scalar * vector[i];
    return result;
}

template<class T, int size>
bool Vector<T, size>::isNull() const
{
    for (int i = 0; i < size; i++)
        if (vector[i] != 0)
            return false;
    return true;
}

template<class T, int size>
void Vector<T, size>::print(std::ostream &out) const
{
    for (int i = 0; i < size; i++)
        out << vector[i] << ' ';
    out << std::endl;
}

