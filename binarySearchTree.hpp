#include "arrayBasedQueue.hpp"

template <typename T>
class Node
{
private:
  Node<T> *left = nullptr;
  Node<T> *right = nullptr;
  T data;

  friend class BinarySearchTree<T>;

public:
  Node() {}

  Node(T data) : data(data) {}
};

template <typename T>
class BinarySearchTree
{
private:
  Node<T> *root = nullptr;
  int count = 0;

  void insert(Node<T> *&node, T data)
  {
    if (node == nullptr)
    {
      node = new Node<T>(data);
    }
    else if (data <= node->data)
    {
      insert(node->left, data);
    }
    else
    {
      insert(node->right, data);
    }
  }

  Node<T> *find(Node<T> *node, T data)
  {
    if (node == nullptr)
    {
      return nullptr;
    }
    else if (node->data == data)
    {
      return node;
    }
    else if (data < node->data)
    {
      return find(node->left, data);
    }
    else
    {
      return find(node->right, data);
    }
  }

  Node<T> *getMinNode(Node<T> *node)
  {
    return node->left ? getMinNode(node->left) : node;
  }

  Node<T> *getMaxNode(Node<T> *node)
  {
    return node->right ? getMaxNode(node->right) : node;
  }

  int height(Node<T> *node)
  {
    if (node == nullptr)
    {
      return -1;
    }
    else
    {
      int leftHeight = height(node->left);
      int rightHeight = height(node->right);

      return ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
    }
  }

public:
  BinarySearchTree()
  {
  }

  void insert(T data)
  {
    insert(root, data);
    count++;
  }

  bool find(T data, T *output)
  {
    Node<T> *result = find(root, data);

    if (result != nullptr)
    {
      *output = result->data;
      return true;
    }

    return false;
  }

  bool exists(T data)
  {
    return find(root, data) != nullptr;
  }

  T getMin()
  {
    if (root == nullptr)
    {
      throw std::out_of_range("Binary search tree is empty.");
    }

    return getMinNode(root)->data;
  }

  T getMax()
  {
    if (root == nullptr)
    {
      throw std::out_of_range("Binary search tree is empty.");
    }

    return getMaxNode(root)->data;
  }

  int height()
  {
    return height(root);
  }

  void levelOrderTraversal()
  {
    if (count == 0)
    {
      std::cout << "Empty Binary Search Tree\n";
    }

    Queue<Node<T> *> q(count);
    q.enqueue(root);

    while (!q.isEmpty())
    {
      Node<T> *current = q.front();
      std::cout << current->data << " ";

      if (current->left != nullptr)
        q.enqueue(current->left);
      if (current->right != nullptr)
        q.enqueue(current->right);

      q.dequeue();
    }
  }
};