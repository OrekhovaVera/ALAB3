#include "InfixCalculator.h"

int InfixCalculator::evaluate(const std::string &expression) {
    postfixExpression = converter.convertToRPN(expression);
    resultOfEvaluation = postfix.evaluatePostfixExpression(postfixExpression);
    return resultOfEvaluation;
}