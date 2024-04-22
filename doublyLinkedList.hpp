#include <iostream>
#include <stdexcept>

template <typename T>
class Node
{
public:
  Node<T> *prev = nullptr;
  T data;
  Node<T> *next = nullptr;

  Node() {}

  Node(T data) : data(data) {}
};

template <typename T>
class DoublyLinkedList
{
private:
  Node<T> *head = nullptr;
  Node<T> *tail = nullptr;
  int count = 0;

public:
  DoublyLinkedList() {}

  ~DoublyLinkedList()
  {
    clear();
  }

  void insertFront(T data)
  {
    Node<T> *newNode = new Node(data);

    if (count == 0)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }

    count++;
  }

  void insertBack(T data)
  {
    Node<T> *newNode = new Node(data);

    if (count == 0)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    }

    count++;
  }

  void insertAt(int index, T data)
  {
    if (index < 0 || index > count)
    {
      throw std::out_of_range("Inserting at given index is out of range for this list.");
    }
    else if (index == 0)
    {
      insertFront(data);
    }
    else if (index == count)
    {
      insertBack(data);
    }
    else if (index <= count / 2)
    {
      Node<T> *newNode = new Node(data);
      Node<T> *temp = head;

      for (int i = 0; i < index - 1; i++)
      {
        temp = temp->next;
      }

      newNode->next = temp->next;
      newNode->prev = temp;
      newNode->next->prev = newNode;
      temp->next = newNode;

      count++;
    }
    else
    {
      Node<T> *newNode = new Node(data);
      Node<T> *temp = tail;

      for (int i = count - 1; i > index; i--)
      {
        temp = temp->prev;
      }

      newNode->prev = temp->prev;
      newNode->next = temp;
      newNode->prev->next = newNode;
      temp->prev = newNode;

      count++;
    }
  }

  void deleteFront()
  {
    if (count == 0)
    {
      return;
    }
    else if (count == 1)
    {
      delete head;
      head = nullptr;
      tail = nullptr;
      count = 0;
    }
    else
    {
      Node<T> *firstNode = head;

      head = firstNode->next;
      head->prev = nullptr;
      delete firstNode;

      count--;
    }
  }

  void deleteBack()
  {
    if (count == 0)
    {
      return;
    }
    else if (count == 1)
    {
      delete head;
      head = nullptr;
      tail = nullptr;
      count = 0;
    }
    else
    {
      Node<T> *lastNode = tail;
      tail = lastNode->prev;
      tail->next = nullptr;
      delete lastNode;

      count--;
    }
  }

  void deleteAt(int index)
  {
    if (index < 0 || index >= count)
    {
      throw std::out_of_range("Deletion of the element at given index is out of range.");
    }
    else if (count == 1)
    {
      deleteFront();
    }
    else if (index == count - 1)
    {
      deleteBack();
    }
    else if (index <= count / 2)
    {
      Node<T> *temp = head;

      for (int i = 0; i < index - 1; i++)
      {
        temp = temp->next;
      }

      Node<T> *deletingNode = temp->next;
      temp->next = deletingNode->next;
      deletingNode->next->prev = temp;

      delete deletingNode;

      count--;
    }
    else
    {
      Node<T> *temp = tail;

      for (int i = count - 1; i > index; i--)
      {
        temp = temp->prev;
      }

      Node<T> *deletingNode = temp->prev;
      temp->prev = deletingNode->prev;
      deletingNode->prev->next = temp;

      delete deletingNode;

      count--;
    }
  }

  T getFront()
  {
    if (count == 0)
    {
      throw std::out_of_range("Cannot retrive front from an empty list.");
    }
    return head->data;
  }

  T getBack()
  {
    if (count == 0)
    {
      throw std::out_of_range("Cannot retrive back from an empty list.");
    }

    return tail->data;
  }

  T getAt(int index)
  {
    if (index == 0)
    {
      return getFront();
    }
    else if (index == count - 1)
    {
      return getBack();
    }
    else if (index <= count / 2)
    {
      Node<T> *temp = head;

      for (int i = 0; i < index; i++)
      {
        temp = temp->next;
      }

      return temp->data;
    }
    else
    {
      Node<T> *temp = tail;

      for (int i = count; i > index; i--)
      {
        temp = temp->prev;
      }

      return temp->data;
    }
  }

  void reverse()
  {
    if (count == 0 || count == 1)
    {
      return;
    }

    Node<T> *prev = nullptr;
    Node<T> *current = head;
    Node<T> *next = nullptr;

    tail = head;

    while (current != nullptr)
    {
      next = current->next;
      current->prev = next;
      current->next = prev;
      prev = current;
      current = next;
    }

    head = prev;
  }

  void display()
  {
    Node<T> *temp = head;

    while (temp != nullptr)
    {
      std::cout << temp->data << " ";
      temp = temp->next;
    }

    std::cout << "\n";
  }

  void clear()
  {
    if (count == 0)
    {
      return;
    }
    else if (count == 1)
    {
      deleteFront();
    }
    else
    {
      Node<T> *temp = head;
      Node<T> *deletingNode = nullptr;

      while (temp != nullptr)
      {
        deletingNode = temp;
        temp = temp->next;
        delete deletingNode;
      }

      head = nullptr;
      tail = nullptr;
      count = 0;
    }
  }

  int getCount()
  {
    return count;
  }

  bool isEmpty()
  {
    return count == 0;
  }
};