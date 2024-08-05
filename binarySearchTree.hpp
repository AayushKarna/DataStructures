#include "arrayBasedQueue.hpp"

template <typename T>
class Node
{
public:
  Node<T> *left = nullptr;
  Node<T> *right = nullptr;
  T data;

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
      return nullptr;

    if (node->data == data)
    {
      return node;
    }
    else if (node->data < data)
    {
      return find(node->right, data);
    }
    else
    {
      return find(node->left, data);
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

  int findHeight(Node<T> *node)
  {
    if (node == nullptr)
      return -1;

    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
  }

  void inOrderTraversal(Node<T> *node)
  {
    if (node == nullptr)
      return;
    inOrderTraversal(node->left);
    std::cout << node->data << " ";
    inOrderTraversal(node->right);
  }

  void preOrderTraversal(Node<T> *node)
  {
    if (node == nullptr)
      return;
    std::cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
  }

  void postOrderTraversal(Node<T> *node)
  {
    if (node == nullptr)
      return;

    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    std::cout << node->data << " ";
  }

public:
  void insert(T data)
  {
    insert(root, data);
    count++;
  }

  bool exists(T data)
  {
    return find(root, data) ? true : false;
  }

  T getMin()
  {
    if (root == nullptr)
    {
      throw std::out_of_range("Empty Binary Search Tree!");
    }
    else
    {
      return getMinNode(root)->data;
    }
  }

  T getMax()
  {
    if (root == nullptr)
    {
      throw std::out_of_range("Empty Binary Search Tree!");
    }
    else
    {
      return getMaxNode(root)->data;
    }
  }

  int getHeight()
  {
    return findHeight(root);
  }

  void levelOrderTraversal()
  {
    if (root == nullptr)
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

  void inOrderTraversal()
  {
    if (root == nullptr)
    {
      std::cout << "Empty Binary Search Tree" << "\n";
    }
    else
    {
      inOrderTraversal(root);
    }
  }

  void preOrderTraversal()
  {
    if (root == nullptr)
    {
      std::cout << "Empty Binary Search Tree" << "\n";
    }
    else
    {
      preOrderTraversal(root);
    }
  }
  void postOrderTraversal()
  {
    if (root == nullptr)
    {
      std::cout << "Empty Binary Search Tree" << "\n";
    }
    else
    {
      postOrderTraversal(root);
    }
  }
};