#include "../arrayBasedStack.hpp"

void reverseString(char *str)
{
  Stack<char> characterStack;

  for (int i = 0; str[i] != '\0'; i++)
  {
    characterStack.push(str[i]);
  }

  int i = 0;
}

int main()
{
  char str[51];
  std::cout << "Enter a random string: ";
  std::cin >> str;
  std::cout << "String before reverse: " << str << "\n";
  reverseString(str);
  std::cout << "String after reverse: " << str << "\n";
}