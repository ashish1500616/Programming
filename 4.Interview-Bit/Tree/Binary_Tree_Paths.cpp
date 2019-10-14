/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void findPathsToLeafs(TreeNode *A, vector<vector<int>> &res, vector<int> sub)
{
    if (A == nullptr)
        return;
    sub.push_back(A->val);
    if (A->left == nullptr && A->right == nullptr)
    {
        res.push_back(sub);
        return;
    }
    findPathsToLeafs(A->left, res, sub);
    findPathsToLeafs(A->right, res, sub);
}
vector<vector<int>> Solution::solve(TreeNode *A)
{
    vector<vector<int>> ans;
    findPathsToLeafs(A, ans, vector<int>());
    return ans;
}
