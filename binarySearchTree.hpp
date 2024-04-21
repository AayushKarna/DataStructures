#include <iostream>

template <typename T>
class Node
{
private:
  Node *left = nullptr;
  Node *right = nullptr;
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

  Node<T> *find(T data)
  {
  }
};