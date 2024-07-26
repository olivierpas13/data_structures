#include <iostream>
#include <stack>
#include <string>

namespace InfixToPostfix
{
    // Function to check if a character is an operator
    bool isOperator(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

    // Function to get the precedence of an operator
    int getPrecedence(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        else if (op == '*' || op == '/')
            return 2;
        return 0;
    }

    // Function to convert infix expression to postfix expression
    std::string convertToPostfix(const std::string &infix)
    {
        std::stack<char> stack;
        std::string postfix;

        for (char c : infix)
        {
            if (isalnum(c))
            {
                postfix += c;
            }
            else if (c == '(')
            {
                stack.push(c);
            }
            else if (c == ')')
            {
                while (!stack.empty() && stack.top() != '(')
                {
                    postfix += stack.top();
                    stack.pop();
                }
                stack.pop(); // Pop '(' from the stack
            }
            else if (isOperator(c))
            {
                while (!stack.empty() && getPrecedence(stack.top()) >= getPrecedence(c))
                {
                    postfix += stack.top();
                    stack.pop();
                }
                stack.push(c);
            }
        }

        while (!stack.empty())
        {
            postfix += stack.top();
            stack.pop();
        }

        return postfix;
    }
}

int main()
{
    std::string infixExpression;
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infixExpression);

    std::string postfixExpression = InfixToPostfix::convertToPostfix(infixExpression);
    std::cout << "Postfix expression: " << postfixExpression << std::endl;

    return 0;
}