#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode {
  int data;
  struct BinaryTreeNode *left;
  struct BinaryTreeNode *right;
};

void Preorder(struct BinaryTreeNode *root) {
  if (root) {
    printf("%d", root->data);
  }
  Preorder(root->left);
  Preorder(root->right);
}
