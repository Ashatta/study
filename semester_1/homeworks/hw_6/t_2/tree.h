#pragma once

class Node
{
    public:
        virtual int calculate() = 0;
        virtual void print() = 0;
        virtual ~Node() {}
};

class Number : public Node
{
    public:
        Number(std::ifstream &in) { in >> value; }
        int calculate() { return value; }
        void print() { std::cout << value; }

    private:
        int value;
};

class Expression : public Node
{
    public:
        Expression(std::ifstream &in);
        ~Expression();
        int calculate();
        void print();

    private:
        char operation;
        Node * left;
        Node * right;

        Node * getNode(std::ifstream &in);
        bool isInvalidOperation(char oper);
};

