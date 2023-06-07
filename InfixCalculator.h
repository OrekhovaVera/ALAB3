#ifndef ALR3_INFIXCALCULATOR_H
#define ALR3_INFIXCALCULATOR_H

#include "Converter.h"
#include "PostfixCalculator.h"
#include <iostream>
#include <string>

class InfixCalculator{
public:
    int evaluate(const std::string& expression);
    int resultOfEvaluation;
    std::string postfixExpression;
private:
    PostfixCalculator postfix;
    Converter converter;
};


#endif //ALR3_INFIXCALCULATOR_H
