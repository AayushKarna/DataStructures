#include <iostream>
#include <stdexcept>

template <typename T>
class Stack
{
private:
  T *A;
  int maxSize;
  int top = -1;

public:
  Stack(int size = 101) : maxSize(size)
  {
    if (size <= 0 || size > 10000)
    {
      throw std::invalid_argument("Invalid stack size. Size must be between 1 and 10,000");
    }

    A = new T[maxSize];
  }

  ~Stack()
  {
    delete[] A;
  }

  void push(T data)
  {
    if (top == maxSize - 1)
    {
      throw std::overflow_error("Error: Stack Overflow");
    }
    A[++top] = data;
  }

  T pop()
  {
    if (top == -1)
    {
      throw std::out_of_range("Cannot pop from an empty stack");
    }

    T temp = A[top];
    top--;
    return temp;
  }

  T peek()
  {
    if (top == -1)
    {
      throw std::out_of_range("Stack is empty");
    }

    return A[top];
  }

  int getSize()
  {
    return top + 1;
  }

  // this print() is not a typical operation of stack, it is only for testing
  void print()
  {
    for (int i = 0; i <= top; i++)
    {
      std::cout << A[i] << " ";
    }

    std::cout << "\n";
  }
};