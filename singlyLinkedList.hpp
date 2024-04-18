#include <iostream>
#include <stdexcept>

template <typename T>
class Node
{
public:
  T data;
  Node *next = nullptr;

  Node() {}

  Node(T data) : data(data) {}
};

template <typename T>
class SinglyLinkedList
{
private:
  Node<T> *head = nullptr, *tail = nullptr;
  int count = 0;

public:
  SinglyLinkedList() {}

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
      tail->next = newNode;
      tail = newNode;
    }

    count++;
  }

  void insertAt(int index, T data)
  {
    if (index < 0 || index > count)
    {
      throw std::out_of_range("Inserting at the given index is out of bound.");
      return;
    }
    else if (count == 0)
    {
      insertFront(data);
    }
    else if (index == count)
    {
      insertBack(data);
    }
    else
    {
      Node<T> *newNode = new Node(data);

      Node<T> *temp = head;
      for (int i = 0; i < index - 1; i++)
      {
        temp = temp->next;
      }

      newNode->next = temp->next;
      temp->next = newNode;
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
      Node<T> *temp = head;
      while (temp->next != tail)
      {
        temp = temp->next;
      }

      delete tail;
      tail = temp;
      tail->next = nullptr;

      count--;
    }
  }

  void deleteAt(int index)
  {
    if (index < 0 || index >= count)
    {
      throw std::out_of_range("Index is out of range!");
      return;
    }
    else if (index == 0)
    {
      deleteFront();
    }
    else if (index == count - 1)
    {
      deleteBack();
    }
    else
    {
      Node<T> *temp = head;

      for (int i = 0; i < index - 1; i++)
      {
        temp = temp->next;
      }

      Node<T> *indexNode = temp->next;
      temp->next = indexNode->next;
      delete indexNode;
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
    if (index < 0 || index >= count)
    {
      throw std::out_of_range("Index is out of range!");
    }
    else if (index == 0)
    {
      return getFront();
    }
    else if (index == count - 1)
    {
      return getBack();
    }
    else
    {
      Node<T> *temp = head;
      for (int i = 0; i < index; i++)
      {
        temp = temp->next;
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

  void clearList()
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

  int getCount()
  {
    return count;
  }

  bool isEmpty()
  {
    return count == 0;
  }
};