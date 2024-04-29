#include "BinarySearchTree.hpp"

int main()
{
  BinarySearchTree<int> bst;

  bst.insert(50);
  bst.insert(30);
  bst.insert(70);
  bst.insert(20);
  bst.insert(40);
  bst.insert(60);
  bst.insert(80);

  std::cout << "Does 40 exist in the tree? " << (bst.exists(40) ? "Yes" : "No") << "\n";

  std::cout << "Minimum value in BST: " << bst.getMin() << "\n";
  std::cout << "Maximum value in BST: " << bst.getMax() << "\n";

  std::cout << "Height of the BST: " << bst.height() << "\n";

  std::cout << "Pre-order traversal: ";
  bst.preOrderTraversal();
  std::cout << "\n";

  std::cout << "In-order traversal: ";
  bst.inOrderTraversal();
  std::cout << "\n";

  std::cout << "Post-order traversal: ";
  bst.postOrderTraversal();
  std::cout << "\n";

  std::cout << "Level-order traversal: ";
  bst.levelOrderTraversal();
  std::cout << "\n";

  return 0;
}
