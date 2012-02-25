#pragma once
#include <string>

class Polynomial
{
    public:
        Polynomial() :
            mName(" "),
            guard(new Term),
            last(guard)
        {}
        ~Polynomial();

        bool isEmpty() const { return guard->next == NULL; }
        void insert(int exp, int coeff);
        double calculate(double x);
        void append(int exp, int coeff);
        void setName(std::string name) { mName = name; }
        void remove();
        std::string name() const { return mName; }
        void print() const;
        Polynomial& operator =(const Polynomial &p);

    private:
        struct Term
        {
            int exp;
            int coeff;
            Term * next;

            Term(int e = 0, int c = 0, Term * n = NULL) :
                exp(e),
                coeff(c),
                next(n)
            {}
            ~Term() {}
        };
        std::string mName;
        Term * guard;
        Term * last;

    friend bool operator ==(Polynomial &p1, Polynomial &p2);
    friend std::istream& operator >>(std::istream &in, Polynomial &p);
    friend Polynomial operator +(const Polynomial &p1, const Polynomial &p2);
};

