#include "PostfixCalculator.h"

PostfixCalculator::PostfixCalculator() = default;

int PostfixCalculator::evaluatePostfixExpression(const std::string& expression) //принимает строку expression, содержащую постфиксное выражение, вычисляет значение и возвращает результат
{
    int number = 0;

    for (char c : expression) // временная переменная для сбора чисел (если число состоит из более, чем одной цифры)
    {
        if (isdigit(c)) //проверка является ли символ "c" цифрой
        {
            number = number * 10 + (c - '0'); // собираем число из отдельных цифр
        }
        else if (c == ' ') //если "с" пробел
        {
            if (number != 0) //если собрали цифры
            {
                stack.push(number); // добавляем в стек
                number = 0; //сбрасываем временную переменную, где хранился операнд, чтобы начать сбор нового числа
            }
        }
        else if (isOperator(c)) //выполнение арифметических операций над двумя последними элементами/операндами в стеке
        {
            if (stack.size() < 2) //проверяется, достаточно ли элементов в стеке для выполнения операции
            {
                // Недостаточно операндов для выполнения операции
                throw std::runtime_error("Invalid expression");
            }

            int operand2 = stack.pop();
            int operand1 = stack.pop();
            int result = performOperation(c, operand1, operand2); //извлекаются два последних элемента из стека и выполняется соответствующая операция с помощью функции performOperation()
            stack.push(result);
        }
        else
        {
            // Некорректный символ в выражении
            throw std::runtime_error("Invalid expression");
        }
    }

    if (number != 0) //если временная переменная состоит из цифр
    {
        stack.push(number);
    }

    if (stack.size() != 1)
    {
        // В конце выражения осталось больше одного значения в стеке
        throw std::runtime_error("Invalid expression");
    }

    return stack.top();
}

bool PostfixCalculator::isOperator(char c)  //проверка является ли символ "c" математическим оператором
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int PostfixCalculator::performOperation(char operation, int operand1, int operand2)
{
    switch (operation)
    {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0)
            {
                throw std::runtime_error("Invalid expression");
            }
            return operand1 / operand2;
        default:
            throw std::runtime_error("Invalid expression");
    }
}
