#include "arrayBasedQueue.hpp"

int main()
{
  Queue<int> q(5);

  try
  {
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();

    std::cout << "Front element: " << q.front() << "\n";
    std::cout << "Rear element: " << q.rear() << "\n";
    std::cout << "Queue size: " << q.queueSize() << "\n";

    int dequeued = q.dequeue();
    std::cout << "Dequeued element: " << dequeued << "\n";
    q.print();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.print();

    std::cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << "\n";
    std::cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << "\n";

    q.enqueue(70);
  }
  catch (const std::exception &e)
  {
    std::cerr << "Error: " << e.what() << "\n";
  }

  return 0;
}
