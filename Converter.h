#ifndef ALR3_CONVERTER_H
#define ALR3_CONVERTER_H

#include "Stack.h"
#include "Queue.h"
#include <string>

class Converter {
public:
    std::string convertToRPN(const std::string& expression);

private:
    bool isOperator(char c);
    int precedence(char c);
    std::string sanitizeExpression(const std::string& expression);

    bool isNumber(const std::string &token);
};

#endif //ALR3_CONVERTER_H
