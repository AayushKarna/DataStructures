#include "arrayBasedStack.hpp"

int main()
{
  Stack<int> intStack;
  try
  {
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.print();

    std::cout << "Top element is: " << intStack.getTop() << "\n";

    intStack.pop();
    intStack.print();

    intStack.pop();
    intStack.pop();
    intStack.print();

    intStack.pop();
  }
  catch (const std::exception &e)
  {
    std::cout << e.what() << "\n";
  }

  return 0;
}