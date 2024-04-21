#include "singlyLinkedList.hpp"

template <typename T>
class Queue
{
private:
  SinglyLinkedList<T> list;

public:
  Queue() {}

  ~Queue()
  {
    clear();
  }

  void enqueue(T data)
  {
    list.insertBack(data);
  }

  T dequeue()
  {
    T temp = list.getFront();
    list.deleteFront();
    return temp;
  }

  T front()
  {
    return list.getFront();
  }

  T rear()
  {
    return list.getBack();
  }

  int queueSize()
  {
    return list.getCount();
  }

  bool isEmpty()
  {
    return list.isEmpty();
  }

  void print()
  {
    if (queueSize() == 0)
    {
      std::cout << "Queue is empty.\n";
      return;
    }

    std::cout << "Queue from head to tail: ";
    list.display();
  }

  void clear()
  {
    list.clear();
  }
};