#pragma once

template<class T>
class Hasher
{
public:
    virtual int hash(T const &value) = 0;
};

