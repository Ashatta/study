#pragma once

class Node
{
    public:
        virtual int calculate() = 0;
        virtual void print(std::ostream &out) = 0;
        virtual ~Node() {}
};

class Number : public Node
{
    public:
        Number(std::istream &in) { in >> value; }
        int calculate() { return value; }
        void print(std::ostream &out) { out << value; }

    private:
        int value;
};

class Expression : public Node
{
    public:
        Expression(std::istream &in);
        ~Expression();
        int calculate();
        void print(std::ostream &out);

    private:
        char operation;
        Node * left;
        Node * right;

        Node * getNode(std::istream &in);
        bool isInvalidOperation(char oper);
};

