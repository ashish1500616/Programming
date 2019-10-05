/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode *node)
{
    if (node == nullptr)
        return 0;
    else
        return (1 + (max(height(node->left), height(node->right))));
}
int checkBalanced(TreeNode *node)
{
    if (node == nullptr)
        return 1;

    int lh = height(node->left);
    int rh = height(node->right);
    if ((abs(lh - rh) <= 1) && (checkBalanced(node->left) && checkBalanced(node->right)))
    {
        return 1;
    }
    return 0;
}
int Solution::isBalanced(TreeNode *A)
{
    return checkBalanced(A) ?  1 : 0 ;
}
