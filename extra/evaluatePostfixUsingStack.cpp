// can use any of stack implementation i.e. can also use array based, can also use linked list based
#include "../linkedListBasedStack.hpp"
#include <string>
#include <cctype>

bool isNumber(std::string s)
{
  if (s.empty())
  {
    return false;
  }

  int start = 0;
  if (s[0] == '-' || s[0] == '+')
  {
    if (s.size() == 1)
    {
      return false;
    }

    start = 1;
  }

  for (int i = start; i < s.size(); i++)
  {
    if (!std::isdigit(s[i]))
    {
      return false;
    }
  }

  return true;
}

int evaluatePostfix(std::string exp)
{
  if (exp.size() < 3)
  {
    throw std::invalid_argument("Invalid postfix expression: too short.");
  }

  Stack<int> operandStack;

  for (char &c : exp)
  {
    if (c == ',')
    {
      c = ' ';
    }
  }

  // More on this string manupulation here: https://stackoverflow.com/a/14266139/10305798
  std::string delimiter = " ";
  size_t pos = 0;
  std::string token;

  while ((pos = exp.find(delimiter)) != std::string::npos)
  {
    token = exp.substr(0, pos);

    if (!token.empty())
    {
      if (token == "/" || token == "*" || token == "+" || token == "-")
      {
        if (operandStack.getSize() < 2)
        {
          throw std::invalid_argument("Invalid expression: insufficient operands for operation.");
        }
        else
        {
          int operand1 = operandStack.pop();
          int operand2 = operandStack.pop();

          if (token == "/" && operand1 == 0)
          {
            throw std::domain_error("Division by zero error.");
          }

          if (token == "/")
          {
            operandStack.push(operand2 / operand1);
          }
          else if (token == "*")
          {
            operandStack.push(operand2 * operand1);
          }
          else if (token == "+")
          {
            operandStack.push(operand2 + operand1);
          }
          else
          {
            operandStack.push(operand2 - operand1);
          }
        }
      }
      else if (isNumber(token))
      {
        operandStack.push(std::stoi(token));
      }
    }

    exp.erase(0, pos + delimiter.length());
  }

  if (!exp.empty())
  {
    if (exp == "/" || exp == "*" || exp == "+" || exp == "-")
    {
      if (operandStack.getSize() < 2)
      {
        throw std::invalid_argument("Invalid expression: insufficient operands for operation");
      }

      int operand1 = operandStack.pop();
      int operand2 = operandStack.pop();

      if (exp == "/" && operand1 == 0)
      {
        throw std::domain_error("Division by zero error.");
      }

      if (exp == "/")
      {
        operandStack.push(operand2 / operand1);
      }
      else if (exp == "*")
      {
        operandStack.push(operand2 * operand1);
      }
      else if (exp == "+")
      {
        operandStack.push(operand2 + operand1);
      }
      else
      {
        operandStack.push(operand2 - operand1);
      }
    }
    else
    {
      throw std::invalid_argument("Invalid expression: last element must be an operator.");
    }
  }

  // std::cout << exp << "\n";
  if (operandStack.getSize() == 1)
  {
    return operandStack.pop();
  }
  else
  {
    throw std::invalid_argument("Invalid expression: incorrect number of item in stack after evaluation.");
  }
}

int main()
{
  try
  {
    std::cout << evaluatePostfix("3 4 +") << "\n"; // 7

    std::cout << evaluatePostfix("5 1 2 + 4 * + 3 -") << "\n"; // 14

    std::cout << evaluatePostfix("12 3 - 2 * 8 +") << "\n"; // 26

    std::cout << evaluatePostfix("10 4 - 1 -") << "\n"; // 5

    std::cout << evaluatePostfix("100 10 / 5 /") << "\n"; // 2

    std::cout << evaluatePostfix("6 -3 +") << "\n"; // 3

    std::cout << evaluatePostfix("10 0 /") << "\n"; // division by 0 error
  }
  catch (const std::exception &e)
  {
    std::cerr << "Caught an exception: " << e.what() << "\n";
  }

  return 0;
}
