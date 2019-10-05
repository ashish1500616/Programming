/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode *A)
{
    vector<int> ans;
    if (A == nullptr)
        return ans;
    stack<TreeNode *> s;
    s.push(A);
    while (!s.empty())
    {
        TreeNode *node = s.top();
        ans.emplace_back(node->val);
        //Important Poping out ...here.
        s.pop();
        if (node->right)
        {
            s.push(node->right);
        }
        if (node->left)
        {
            s.push(node->left);
        }
    }
    return ans;
}
