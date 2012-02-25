#include <iostream>
#include <string>
#include "polynomial.h"
#include "power.h"

Polynomial::~Polynomial() 
{ 
    last = NULL;
    Term * tmp = guard->next;

    while (tmp)
    {
        delete guard;
        guard = tmp;
        tmp = tmp->next;
    }
    delete guard;
}

void Polynomial::append(int exp, int coeff)
{
    last->next = new Term(exp, coeff);
    last = last->next;
}

void Polynomial::insert(int exp, int coeff)
{
    if (isEmpty())
    {
        append(exp, coeff);
        return;
    }

    Polynomial::Term * tmp = guard;
    while (tmp->next && tmp->next->exp < exp)
        tmp = tmp->next;

    if (!tmp->next)
        append(exp, coeff);
    else if (tmp->next->exp == exp)
        tmp->next->coeff += coeff;
    else 
        tmp->next = new Polynomial::Term(exp, coeff, tmp->next);
} 

void Polynomial::remove()
{
    if (!isEmpty())
    {
        Term * prev = guard->next;
        guard->next = NULL;
        last = guard;
        Term * curr = prev->next;

        while (curr)
        {
            delete prev;
            prev = curr;
            curr = curr->next;
        }
        delete prev;
    }

    mName = " ";
}

double Polynomial::calculate(double x)
{
    if (isEmpty())
        return 0;

    int pow = 0;
    double result = 0;
    double currx = 1;
    Polynomial::Term * tmp = guard->next;

    while (tmp)
    {
        result += tmp->coeff * (currx *= power(x, tmp->exp - pow));
        tmp = tmp->next;
    }

    return result;
}

bool operator ==(Polynomial &p1, Polynomial &p2)
{
    if (p1.isEmpty())
        if (p2.isEmpty())
            return true;
        else
            return false;
    if (p2.isEmpty())
        return false;

    Polynomial::Term * tmp1 = p1.guard->next;
    Polynomial::Term * tmp2 = p2.guard->next;

    while (tmp1 && tmp2)
    {
        if (tmp1->exp != tmp2->exp || 
                tmp1->coeff != tmp2->coeff)
            return false;
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    if (!tmp1 && tmp2 || tmp1 && !tmp2)
        return false;

    return true;
}

std::istream& operator >>(std::istream &in, Polynomial &p)
{
    int exp = 0;
    int coeff = 0;

    while (true)
    {
        in >> coeff;
        if (!coeff)
            return in;
        in >> exp;
        p.insert(exp, coeff);
    }

    return in;
}

void Polynomial::print() const
{
    std::cout << mName;
    if (!isEmpty())
    {
        Term * tmp = guard->next;
        while (tmp)
        {
            std::cout << ' ' << tmp->coeff << ' ' << tmp->exp;
            tmp = tmp->next;
        }
    }
    std::cout << std::endl;
}

Polynomial operator +(const Polynomial &p1, const Polynomial &p2)
{
    Polynomial result;
   
    Polynomial::Term * tmp1 = p1.guard->next;
    Polynomial::Term * tmp2 = p2.guard->next;

    while (tmp1 || tmp2)
    {
        while (tmp1 && (!tmp2 || tmp1->exp < tmp2->exp))
        {
            result.append(tmp1->exp, tmp1->coeff);
            tmp1 = tmp1->next;
        }
        while (tmp1 && tmp2 && tmp1->exp == tmp2->exp)
        {
            result.append(tmp1->exp, tmp1->coeff + tmp2->coeff);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        while (tmp2 && (!tmp1 || tmp1->exp > tmp2->exp))
        {
            result.append(tmp2->exp, tmp2->coeff);
            tmp2 = tmp2->next;
        }
    }

    return result;
}

Polynomial& Polynomial::operator =(const Polynomial &p)
{
    this->remove();

    if (p.isEmpty())
        return *this;

    Term * tmp = p.guard->next;
    while (tmp)
    {
        this->append(tmp->exp, tmp->coeff);
        tmp = tmp->next;
    }

    return *this;
}

