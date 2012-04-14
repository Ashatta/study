#pragma once

/** Exception class InvalidArgumentException is thrown when expected
 *  argument is not an integer number
 */
class InvalidArgumentException {};
/** Exception class InvalidOperationException is thrown when expected
 *  operation is not allowed (not +, -, * or /)
 */
class InvalidOperationException {};
class DivisionByZeroException {};

/** Abstract class Node represents a node of syntactic tree: number
 *  or expression
 */
class Node
{
public:
    /** Method calculate returns a result of evaluation of expression
     *  represented by Node
     */
    virtual int calculate() = 0;
    /// Method print prints a tree in prefix notation
    virtual void print(std::ostream &out) = 0;
    virtual ~Node() {}
};

/// Class Number represents an integer number as a node of syntactic tree
class Number : public Node
{
public:
    Number(std::istream &in) { in >> value; }
    int calculate() { return value; }
    void print(std::ostream &out) { out << value; }

private:
    int value;
};

/* Class Expression represents a node of syntactic tree that is
 * an expression which consists of two operands an binary operation
 * +, -, * or /
 */
class Expression : public Node
{
public:
    /** Constructor of class Expression takes an expression in form of
     * (<operation sign> <operand1> <operand2>) from stream in where
     * <operand1> and <operand2> may be an expression or an integer
     * number
     */
    Expression(std::istream &in);
    ~Expression();
    /// Method calculate return the result of expression evaluation
    int calculate();
    /** Method print prints an expression in form of 
     *  (<operation sign> <operand1> <operand2>) in stream out
     */
    void print(std::ostream &out);

private:
    char operation;
    Node * left;
    Node * right;

    /** Private method getNode takes Node from stream and decides
     *  whether it is Expression or Number
     */
    Node * getNode(std::istream &in);
    /** Private method isInvalidOperation returns true if operation
     *  is not allowed
     */
    bool isInvalidOperation(char oper);
};

