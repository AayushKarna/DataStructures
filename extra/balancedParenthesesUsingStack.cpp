/*
Defination:
  parentheses: () or {} or []
  expression: any string containing letters, symbols, numbers

When a condition for balanced parentheses to occur?
=> For given expression, for all opening prentheses ('(', '{; or '[') there exists corresponding closing parentheses.

Why useful?
=> Compiler, text editors needs to make sure that all the braces are balanced

Examples:
Expression-->isBalanced
(A+B) --> true
{(A+B)+(C+D)} --> true
{(x+y)*(z) --> false
[2*3]+(A)] --> false
{a+z) --> false

)( --> false (this shows that no of opening brac = no of closing brac will not solve it
[()] --> true
[(]) --> fasle

Properties for balanced parentheses:
1) Number of opening one type of parentheses == Number of corresponding type of closing parentheses; where opening type must be one of (, [ or {
2) Every opening parentheses must find a closing counterpart to its right
3) Every closing parentheses must find an opening counterpart to its left
4) *IMPORTANT*: Last unclosed, first closed [HERE WE CAN USE STACK]
*/

#include "../arrayBasedStack.hpp"

bool isBalanced(std::string expression)
{
  int lengthOfExpression = expression.length();

  if (lengthOfExpression == 0)
  {
    return true;
  }

  Stack<char> openingStack;

  for (int i = 0; i < lengthOfExpression; i++)
  {
    char curr = expression[i];

    if (curr != '(' && curr != ')' && curr != '{' && curr != '}' && curr != '[' && curr != ']')
    {
      continue;
    }
    else if (curr == '(' || curr == '{' || curr == '[')
    {
      openingStack.push(curr);
    }
    else
    {
      if (
          openingStack.isEmpty() ||
          (curr == ')' && openingStack.peek() != '(') ||
          (curr == '}' && openingStack.peek() != '{') ||
          (curr == ']' && openingStack.peek() != '['))
      {
        return false;
      }

      openingStack.pop();
    }
  }

  return openingStack.getSize() == 0;
}

int main()
{
  std::string exp;

  std::cout << "Enter the expression: ";
  std::getline(std::cin, exp);

  std::cout << "Is the parentheses balanced? " << (isBalanced(exp) ? "Yes" : "No") << "\n";
}