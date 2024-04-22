#include "arrayBasedQueue.hpp"

template <typename T>
class Node
{
private:
  Node<T> *left = nullptr;
  Node<T> *right = nullptr;
  T data;

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
      node = new Node(data);
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
    if (count == 0)
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

public:
  BinarySearchTree() {}

  void insert(T data)
  {
    if (count == 0)
    {
      root = new Node(data);
    }
    else
    {
      insert(root, data);
    }

    count++;
  }

  T getMin(Node<T> *node)
  {
    if (count == 0)
    {
      throw std::out_of_range("Binary Search Tree is empty.");
    }
    else if (node->left == nullptr)
    {
      return node->data;
    }
    else
    {
      return getMin(node->left);
    }
  }

  T getMax(Node<T> *node)
  {
    if (count == 0)
    {
      throw std::out_of_range("Binary Search Tree is empty.");
    }
    else if (node->right == nullptr)
    {
      return node->data;
    }
    else
    {
      return getMax(node->right);
    }
  }

  int height(Node<T> *node)
  {
    if (node == nullptr)
    {
      return -1;
    }
    else
    {
      int leftHeight = height(node->right);
      int rightHeight = height(node->left);

      return ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
    }
  }

  void levelOrderTraversal()
  {
    if (count == 0)
    {
      std::cout << "Empty Binary Search Tree\n";
    }

    Queue<Node<T> *> q;
    q.enqueue(root);

    while (!q.isEmpty())
    {
      Node<T> *current = q.front();
      std::cout << current->data << " ";

      if (current->left != nullptr)
        q.enqueue(current->left);
      if (current->right != nullptr)
        q.push(current->right);

      q.pop();
    }
  }
};