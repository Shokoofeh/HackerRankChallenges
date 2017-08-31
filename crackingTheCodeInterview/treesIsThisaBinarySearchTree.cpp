/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

bool leftSubtree(Node* root, int val)
{
  bool result = true;
  if (!root) return true;

  //Pre-Order
  if (root->data >= val) return false;
  if (root->left) result &= leftSubtree(root->left, val);
  if (root->right) result &= leftSubtree(root->right, val);
  return result;
}

bool rightSubtree(Node* root, int val)
{
  bool result = true;
  if (root == NULL) return true;

  //Pre-Order
  if (root->data <= val) return false;
  if (root->left) result &= rightSubtree(root->left, val);
  if (root->right) result &= rightSubtree(root->right, val);
  return result;
}

bool checkBST(Node* root) {
  bool result = true;
  if (!root) return false;
  Node* left = root->left;
  Node* right = root->right;

  if (left)
    if (!leftSubtree(left, root->data)) return false;
  if (right)
    if (!rightSubtree(right, root->data)) return false;
  if (right != NULL && left != NULL && left->data == right->data) return false;

  if (left) result &= checkBST(left);
  if (right) result &= checkBST(right);
  return result;
}

