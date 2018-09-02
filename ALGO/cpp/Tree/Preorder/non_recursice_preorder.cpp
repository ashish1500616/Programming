#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode {
  int data;
  struct BinaryTreeNode *left;
  struct BinaryTreeNode *right;
};

void non_recursive_preorder(BinaryTreeNode *root) {
  stack<BinaryTreeNode *> S;
  while (1) {
    while (root) {
      printf("%d", root->data);
      // push(S,root);
      S.push(root);
      root = root->left;
    }
    // Check If stack is empty
    if (S.empty()) {
      break;
    }
    root = S.top();
    S.pop();
    root = root->right;
  }
  // Implement A funciton to Delete the Stack
  DeleteStack(S);
}
