#include "singlyLinkedList.hpp"

int main()
{
  SinglyLinkedList<int> sll;

  sll.insertBack(10);
  sll.insertBack(20);
  sll.insertBack(30);
  sll.insertBack(40);
  sll.insertFront(5);

  std::cout << "Original List: ";
  sll.display();

  sll.reverse();

  std::cout << "Reversed List: ";
  sll.display();

  std::cout << "Element at index 2: " << sll.getAt(2) << "\n";

  sll.deleteAt(2);

  std::cout << "Modified List after deleting at index 2: ";
  sll.display();

  sll.insertAt(2, 25);

  std::cout << "Modified List after inserting 25 at index 2: ";
  sll.display();

  std::cout << "Front element: " << sll.getFront() << "\n";

  std::cout << "Number of elements: " << sll.getCount() << "\n";

  sll.clearList();

  std::cout << "Cleared List: ";
  sll.display();

  std::cout << "Number of elements after clear: " << sll.getCount() << "\n";

  return 0;
}
