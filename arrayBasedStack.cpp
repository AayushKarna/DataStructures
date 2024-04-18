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

    std::cout << "Top element is: " << intStack.peek() << "\n";

    intStack.clear();
    intStack.print();
    std::cout << "Size of stack after clear is: " << intStack.getSize() << "\n";

    intStack.push(4);
    intStack.push(5);
    intStack.print();

    intStack.pop();
    intStack.print();

    std::cout << "Size of stack is: " << intStack.getSize() << "\n";

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
