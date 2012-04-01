#pragma once
#include "arraystack.h"

/** Exception BracketsDisbalance is thrown in case of
 *  brackets disbalance in input expression =) */
class BracketsDisbalance {};

/** Class PolishConverter converts an expression from infix notation to the postfix one,
 */
class PolishConverter
{
public:
    /** Method convert makes an expression in postfix notation from infix.
     *  Gets an expression from stream source.
     *  Expression in postfix notation will be saved in the stringstream dest.
     */
        void convert(std::istream &source, std::stringstream &dest);
private:
    /** Method isOperation checks whether ch is '+', '-', '*' or '/'. */
    bool isOperation(char ch);
    /** Inline method isLessPriority returns true if operation op1 is of less priority
     *  than operation op2
     */
    bool isLessPriority(char op1, char op2)
    {
        return op1 == '+' || op1 == '-' || op2 == '*' || op2 == '/';
    }

    ArrayStack<char> stack; ///< Stack of operations and brackets.
};
