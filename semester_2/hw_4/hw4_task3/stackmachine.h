#pragma once
#include "arraystack.h"

/** Class StackMachine calculates an expression that is written in postfix notation
 *  receiving it from istream in suggestion that input expression is correct and consists only
 *  of numbers and operation +, -, * and /.
 */
class StackMachine
{
public:
    /** Calculates an expression. Return value is the result of calculation. */
    double calculate(std::istream &source);

private:
    /** Private method calculate does the evaluation of one operation and returns its result. */
    double calculate(double operand1, double operand2, char operation);

    ArrayStack<double> stack; ///< Stack, organised on an array, for intermediate evaluations
};

