#include "linkedListBasedStack.hpp"

int main()
{
  Stack<int> intStack;
  try
  {
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.print();

    std::cout << "Top element is: " << intStack.peek() << "\n";

    intStack.pop();
    intStack.print();

    std::cout << "Size of stack is: " << intStack.getSize() << "\n";

    intStack.pop();
    intStack.pop();
    intStack.print();
    std::cout << "Size of stack is: " << intStack.getSize() << "\n";

    intStack.pop();
  }
  catch (const std::exception &e)
  {
    std::cout << e.what() << "\n";
  }

  return 0;
}