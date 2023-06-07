#include "Converter.h"
#include <sstream>
#include <cctype>
#include <stdexcept>

std::string Converter::convertToRPN(const std::string& expression)
{
    std::string sanitizedExpression = sanitizeExpression(expression);  //санитизация выражения путем удаления лишних пробелов и добавления пропущенных пробелов
    std::istringstream iss(sanitizedExpression);
    std::ostringstream oss;
    Stack<char> operatorStack;
    Queue<std::string> outputQueue;

    std::string token;
    while (iss >> token)
    {
        if (isNumber(token))
        {
            outputQueue.push(token);  //если токен является числом, добавляем его в очередь вывода
        }
        else if (isOperator(token[0]))
        {
            while (operatorStack.size() > 0 && operatorStack.top() != '(' && precedence(token[0]) <= precedence(operatorStack.top()))
            {
                outputQueue.push(std::string(1, operatorStack.pop()));  // переносим операторы из стека операторов в очередь вывода до тех пор, пока выполняются условия приоритета
            }
            operatorStack.push(token[0]);  //добавляем текущий оператор в стек операторов
        }
        else if (token[0] == '(')
        {
            operatorStack.push(token[0]);  //если токен является открывающей скобкой, добавляем его в стек операторов
        }
        else if (token[0] == ')')
        {
            while (operatorStack.size() > 0 && operatorStack.top() != '(')
            {
                outputQueue.push(std::string(1, operatorStack.pop()));  //переносим операторы из стека операторов в очередь вывода до тех пор, пока не встретим открывающую скобку
            }
            if (operatorStack.size() == 0)
            {
                throw std::runtime_error("Entered parentheses are incorrect. Try again.");  // если стек операторов пуст до встречи открывающей скобки, то имеется несогласованность скобок
            }
            operatorStack.pop();  // Удаляем открывающую скобку из стека
        }
        else
        {
            throw std::runtime_error("Entered expression is incorrect. Please try again.");  // если встречен некорректный символ, выбрасываем исключение
        }
    }

    while (operatorStack.size() > 0)
    {
        if (operatorStack.top() == '(' || operatorStack.top() == ')')
        {
            throw std::runtime_error("Entered parentheses are incorrect. Try again.");  //если в стеке остались открывающие или закрывающие скобки, имеется несогласованность скобок
        }
        outputQueue.push(std::string(1, operatorStack.pop()));  //переносим оставшиеся операторы из стека операторов в очередь вывода
    }

    while (!outputQueue.isEmpty())
    {
        oss << outputQueue.pop() << " ";  // извлекаем элементы из очереди вывода и добавляем их в строковый поток
    }

    std::string rpnExpression = oss.str();
    rpnExpression.pop_back();  // удаляем конечный пробел

    return rpnExpression;  //возвращаем обратную польскую запись выражения
}

bool Converter::isNumber(const std::string& token)
{
    for (char c : token)
    {
        if (!isdigit(c))
        {
            return false;  //проверяем, является ли токен числом
        }
    }
    return true;
}


bool Converter::isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';  // проверяем, является ли символ оператором
}

int Converter::precedence(char c)
{
    if (c == '+' || c == '-') {
        return 1;  //возвращаем приоритет оператора "+" или "-"
    } else if (c == '*' || c == '/') {
        return 2;  // возвращаем приоритет оператора "*" или "/"
    }
    return 0;  // если символ не является оператором, возвращаем нулевой приоритет
}

std::string Converter::sanitizeExpression(const std::string& expression)
{
    std::string sanitizedExpression;
    std::string currentNumber;

    for (char c : expression)
    {
        if (std::isspace(c))
        {
            continue;  //пропускаем пробелы
        }

        if (isdigit(c))
        {
            currentNumber += c;  //если символ является цифрой, добавляем его к текущему числу
        }
        else if (isOperator(c))
        {
            if (!currentNumber.empty())
            {
                sanitizedExpression += currentNumber + ' ';  //если текущее число не пустое, добавляем его в выражение и добавляем пробел
                currentNumber.clear();
            }
            sanitizedExpression += c;  //добавляем оператор в выражение
            sanitizedExpression += ' ';  //добавляем пробел после оператора
        }
        else if (c == '(' || c == ')')
        {
            if (!currentNumber.empty())
            {
                sanitizedExpression += currentNumber + ' ';  //если текущее число не пустое, добавляем его в выражение и добавляем пробел
                currentNumber.clear();
            }
            sanitizedExpression += c;  //добавляем скобку в выражение
            sanitizedExpression += ' ';  //добавляем пробел после скобки
        }
        else
        {
            throw std::runtime_error("Некорректный символ.");  //если встречен некорректный символ, выбрасываем исключение
        }
    }

    if (!currentNumber.empty())
    {
        sanitizedExpression += currentNumber + ' ';  //если текущее число не пустое, добавляем его в выражение и добавляем пробел
    }

    return sanitizedExpression;  //возвращаем санитизированное выражение
}
