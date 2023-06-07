#include <iostream>
#include "InfixCalculator.h"

int main()
{
    InfixCalculator infix_calculator;
    std::string infix_expression;
    int result = 0;

    std::cout << "==========================" << std::endl;
    std::cout << "Инфиксный калькулятор" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Введите математическое выражение: " << std::endl;
    std::getline(std::cin, infix_expression); // считываем выражение

    try {
        result = infix_calculator.evaluate(infix_expression);
        std::cout << "==========================" << std::endl;
        std::cout << "Результат: " << result << std::endl;
        std::cout << "==========================" << std::endl;
    } catch (std::runtime_error &e) {
        std::cout << "==========================" << std::endl;
        std::cout << "Ошибка:  " << e.what() << std::endl;
        std::cout << "==========================" << std::endl;
    }


    return 0;
}
