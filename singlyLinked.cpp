#include "singlyLinkedList.hpp"

int main()
{
  SinglyLinkedList<int> list;

  list.insertBack(10);
  list.insertBack(20);
  list.insertBack(30);
  std::cout << "List after inserting at back: ";
  list.display();
  std::cout << "Current count: " << list.getCount() << "\n";

  list.insertFront(5);
  list.insertFront(1);
  std::cout << "List after inserting at front: ";
  list.display();
  std::cout << "Current count: " << list.getCount() << "\n";

  list.insertAt(2, 15);
  std::cout << "List after inserting 15 at index 2: ";
  list.display();
  std::cout << "Current count: " << list.getCount() << "\n";

  list.deleteFront();
  std::cout << "List after deleting front: ";
  list.display();
  std::cout << "Current count: " << list.getCount() << "\n";

  list.deleteBack();
  std::cout << "List after deleting back: ";
  list.display();
  std::cout << "Current count: " << list.getCount() << "\n";

  list.deleteAt(2);
  std::cout << "List after deleting element at index 2: ";
  list.display();
  std::cout << "Current count: " << list.getCount() << "\n";

  list.reverse();
  std::cout << "List after reversing: ";
  list.display();
  std::cout << "Current count: " << list.getCount() << "\n";

  list.clearList();
  std::cout << "List after clearing: ";
  list.display();
  std::cout << "Current count: " << list.getCount() << "\n";

  return 0;
}
