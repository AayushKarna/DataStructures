#include "linkedListBasedQueue.hpp"

int main()
{
  Queue<int> myQueue;

  myQueue.enqueue(10);
  myQueue.enqueue(20);
  myQueue.enqueue(30);

  myQueue.print();

  std::cout << "Front element: " << myQueue.front() << "\n";

  std::cout << "Rear element: " << myQueue.rear() << "\n";

  std::cout << "Dequeued element: " << myQueue.dequeue() << "\n";

  myQueue.print();

  std::cout << "Queue size after dequeue: " << myQueue.queueSize() << "\n";

  myQueue.clear();
  std::cout << "Queue cleared.\n";

  std::cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << "\n";
}
