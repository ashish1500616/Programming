/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void Inorder(TreeNode *A, vector<int> &o)
{
    if (A == nullptr)
        return;
    Inorder(A->left, o);
    o.push_back(A->val);
    Inorder(A->right, o);
}
int Solution::isSymmetric(TreeNode *A)
{
    vector<int> tr;
    Inorder(A, tr);
    int n = tr.size();
    for (int i = 0; i < (n >> 1); i++)
    {
        if (tr[i] != tr[n - i - 1])
            return 0;
    }
    return 1;
}
