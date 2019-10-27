/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int traversal(TreeNode *A)
{
    if (A == nullptr)
        return 0;
    if (A->left == nullptr && A->right == nullptr)
        return A->val;
    int ls = traversal(A->left);
    int rs = traversal(A->right);
    A->val += (ls + rs);
    return A->val;
}
// Dont Check The Value In The Root Node.
void findIfPossible(TreeNode *A, int s, int &ans)
{
    if (A == nullptr)
        return;
    if ((A->left && A->left->val == s) || (A->right && A->right->val == s))
    {
        ans = 1;
        return;
    }
    findIfPossible(A->left, s, ans);
    findIfPossible(A->right, s, ans);
}
int Solution::solve(TreeNode *A)
{

    int sum = traversal(A);
    // cout<<sum<<"\n";
    if ((sum & 1))
        return 0;
    int ans = 0;
    findIfPossible(A, int(sum / 2), ans);
    if (ans)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
