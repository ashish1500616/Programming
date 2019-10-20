/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int ChangeToSum(TreeNode *A)
{
    if (A == nullptr)
        return 0;
    if (A->left == nullptr && A->right == nullptr)
        return A->val;
    if ((ChangeToSum(A->left) + ChangeToSum(A->right)) > A->val)
    {
        A->val = ChangeToSum(A->left) + ChangeToSum(A->right);
    }
    else
    {
        if (A->right != nullptr && A->left != nullptr)
        {
            (A->left->val) = (A->val) - (A->right->val);
        }
        if (A->right && !A->left)
            A->right->val = A->val;
        if (A->left && !A->right)
            A->left->val = A->val;
    }
    return (A->val);
}
TreeNode *Solution::solve(TreeNode *A)
{
    ChangeToSum(A);
    return A;
}
