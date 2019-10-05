/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + max(height(root->left), height(root->right));
    }
}
void printLevel(TreeNode *A, int level, vector<int> &s)
{
    if (A == NULL)
        return;
    if (level == 0)
        s.emplace_back(A->val);
    else if (level >= 1)
    {
        printLevel(A->left, level - 1, s);
        printLevel(A->right, level - 1, s);
    }
}
void printLevelOrder(TreeNode *A, vector<vector<int>> &ans)
{
    int h = height(A);
    for (int i = 0; i < h; i++)
    {
        vector<int> sub;
        printLevel(A, i, sub);
        if (i & 1)
            reverse(sub.begin(), sub.end());
        ans.push_back(sub);
    }
}
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode *A)
{
    vector<vector<int>> ans;
    printLevelOrder(A, ans);
    return ans;
}
