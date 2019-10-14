/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void InorderTraversal(TreeNode *A, vector<int> &IO)
{
    if (A == nullptr)
        return;
    InorderTraversal(A->left, IO);
    IO.push_back(A->val);
    InorderTraversal(A->right, IO);
}
int Solution::kthsmallest(TreeNode *A, int B)
{
    vector<int> o;
    InorderTraversal(A, o);
    return o[B - 1];
}
