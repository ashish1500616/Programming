/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *preOrder(TreeNode *root, TreeNode *prev)
    {
        // Store the right Subtree .
        TreeNode *right = root->right;
        // If Previous is pointing to some node .
        // If previous is pointing to null we gonna make previous to point to root.
        if (prev != nullptr)
        {
            prev->right = root;
        }
        prev = root;
        // if left subtree is present .
        if (root->left)
            prev = preOrder(root->left, prev);
        // Change the left pointer to nullptr .
        root->left = nullptr;
        // If right is a node .
        if (right)
            prev = preOrder(right, prev);
        return prev;

        // return previous node since at each call for eg at node 2  previous would be pointing to 1 but we want it to point to 3.
    }
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        TreeNode *prev = nullptr;
        preOrder(root, prev);
    }
};