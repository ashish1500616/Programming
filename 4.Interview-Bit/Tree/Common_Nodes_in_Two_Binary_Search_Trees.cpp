/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void Inorder(TreeNode *A, vector<int> &v)
{
    if (A == nullptr)
        return;
    Inorder(A->left, v);
    v.push_back(A->val);
    Inorder(A->right, v);
}
int Solution::solve(TreeNode *A, TreeNode *B)
{
    vector<int> Ao, Bo;
    Inorder(A, Ao);
    Inorder(B, Bo);
    int sum = 0;
    for (auto x : Ao)
    {
        if (binary_search(Bo.begin(), Bo.end(), x))
            sum += x;
    }
    return sum;
}
