/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void LevelOrderTraversal(TreeNode *A, vector<int> &order)
{
    if (A == nullptr)
        return;
    queue<TreeNode *> q;
    q.push(A);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        order.push_back(temp->val);
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

int Solution::isSameTree(TreeNode *A, TreeNode *B)
{
    vector<int> Ao, Bo;
    LevelOrderTraversal(A, Ao);
    LevelOrderTraversal(B, Bo);
    if (Ao == Bo)
        return 1;
    else
        return 0;
}
