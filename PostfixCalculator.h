#ifndef ALR3_POSTFIXCALCULATOR_H
#define ALR3_POSTFIXCALCULATOR_H


#include "Stack.h"
#include <cctype>
#include <stdexcept>
#include <string>

class PostfixCalculator
{
public:
    PostfixCalculator();
    int evaluatePostfixExpression(const std::string& expression);

private:
    Stack<int> stack;
    bool isOperator(char c);
    int performOperation(char operation, int operand1, int operand2);
};

#endif //ALR3_POSTFIXCALCULATOR_H
