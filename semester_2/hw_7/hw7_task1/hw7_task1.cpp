#include <iostream>
#include <string>

using namespace std;

class ExceptionToSpoilEverything {};
class ExceptionToSpoilDestructor {};

class A
{
public:
    A(const string &name) : mName(name)
    { cout << "Constructor of A is called for object " << name << endl; }
    ~A() 
    { cout << "Destructor of A is called for object " << mName << endl; }
protected:
    string mName;
};

class B
{
public:
    B(const string &name) : mName(name)
    { 
        cout << "Constructor of evil class B is called for object " 
             << name << endl;
    }
    ~B() 
    { 
        cout << "Destructor of evil class B is called for object " 
             << mName << endl; 
        throw ExceptionToSpoilDestructor();
    }
protected:
    string mName;
};

void spoiler()
{
    A first("first");
    throw ExceptionToSpoilEverything();
}

int main()
{
    try
    {
        spoiler();
    }
    catch (...)
    {
        cout << "Exception is thrown after destructor "
             << "calls for every object of the block...\n" << endl;
    }
    try
    {
        A second("second");
        B third("third");
    } 
    catch (...)
    {
        cout << "...even if it is thrown by one of destructors itself"
             << endl;
    }
    return 0;
}

