#include "doublyLinkedList.hpp"

int main()
{
  DoublyLinkedList<int> dll;

  dll.insertBack(10);
  dll.insertBack(20);
  dll.insertBack(30);
  dll.insertBack(40);
  dll.insertFront(5);

  std::cout << "Original List: ";
  dll.display();

  dll.reverse();

  std::cout << "Reversed List: ";
  dll.display();

  std::cout << "Element at index 2: " << dll.getAt(2) << "\n";

  dll.deleteAt(2);

  std::cout << "Modified List after deleting at index 2: ";
  dll.display();

  dll.insertAt(2, 25);

  std::cout << "Modified List after inserting 25 at index 2: ";
  dll.display();

  std::cout << "Front element: " << dll.getFront() << "\n";
  std::cout << "Back element: " << dll.getBack() << "\n";

  std::cout << "Number of elements: " << dll.getCount() << "\n";

  dll.clearList();

  std::cout << "Cleared List: ";
  dll.display();

  std::cout << "Number of elements after clear: " << dll.getCount() << "\n";

  return 0;
}
