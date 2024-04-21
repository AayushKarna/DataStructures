#include <iostream>
#include <stdexcept>

template <typename T>
class Queue
{
private:
  T *A;
  int maxSize;
  int head = -1, tail = -1;
  int count = 0;

public:
  Queue(int size = 101) : maxSize(size)
  {
    if (size <= 0 || size > 10000)
    {
      throw std::invalid_argument("Invalid queue size. Size must be between 1 and 10,000");
    }

    A = new T[maxSize];
  }

  ~Queue()
  {
    delete[] A;
  }

  void enqueue(T data)
  {
    if (isFull())
    {
      throw std::overflow_error("Queue is full.");
    }
    else if (isEmpty())
    {
      head = tail = 0;
      A[tail] = data;
      count = 1;
    }
    else
    {
      tail = (tail + 1) % maxSize;
      A[tail] = data;
      count++;
    }
  }

  T dequeue()
  {
    if (isEmpty())
    {
      throw std::out_of_range("Cannot dequeue from an empty queue.");
    }

    T temp = A[head];

    if (head == tail)
    {
      head = tail = -1;
      count = 0;
    }
    else
    {
      head = (head + 1) % maxSize;
      count--;
    }

    return temp;
  }

  T front()
  {
    if (isEmpty())
    {
      throw std::out_of_range("Queue is empty.");
    }

    return A[head];
  }

  T rear()
  {
    if (isEmpty())
    {
      throw std::out_of_range("Queue is empty.");
    }

    return A[tail];
  }

  int queueSize()
  {
    return count;
  }

  bool isEmpty()
  {
    return count == 0;
  }

  bool isFull()
  {
    return count == maxSize;
  }

  void print()
  {
    if (isEmpty())
    {
      std::cout << "Queue is empty.\n";
      return;
    }

    std::cout << "Queue elements from head to tail: ";
    int current = head;
    do
    {
      std::cout << A[current] << " ";
      current = (current + 1) % maxSize;
    } while (current != (tail + 1) % maxSize);

    std::cout << "\n";
  }
};