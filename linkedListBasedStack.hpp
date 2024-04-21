#include "singlyLinkedList.hpp"

template <typename T>
class Stack
{
private:
  SinglyLinkedList<T> list;

public:
  Stack() {}

  ~Stack()
  {
    clear();
  }

  void push(T data)
  {
    list.insertFront(data);
  }

  T pop()
  {
    if (list.getCount() == 0)
    {
      throw std::out_of_range("Cannot pop from an empty stack.");
    }

    T temp = list.getFront();
    list.deleteFront();
    return temp;
  }

  T peek()
  {
    if (list.getCount() == 0)
    {
      throw std::out_of_range("Empty Stack!");
    }

    return list.getFront();
  }

  bool isEmpty()
  {
    return list.isEmpty();
  }

  int getSize()
  {
    return list.getCount();
  }

  void clear()
  {
    list.clear();
  }

  // this print is not a typical operation of stack, it is only for testing, it prints stack from top to bottom
  void print()
  {
    if (list.getCount() == 0)
    {
      std::cout << "Stack is empty.\n";
    }

    list.display();
  }
};