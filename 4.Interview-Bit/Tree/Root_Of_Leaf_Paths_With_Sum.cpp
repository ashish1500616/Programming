/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void RLPWS(TreeNode *A, int currSum, vector<vector<int>> &ans, vector<int> sa, int B)
{
    sa.push_back(A->val);
    currSum += A->val;
    if (A->left == nullptr && A->right == nullptr)
    {
        if (currSum == B)
        {
            ans.push_back(sa);
        }
        sa.clear();
        currSum = 0;
        return;
    }
    if (A->left)
        RLPWS(A->left, currSum, ans, sa, B);
    if (A->right)
        RLPWS(A->right, currSum, ans, sa, B);
}

vector<vector<int>> Solution::pathSum(TreeNode *A, int B)
{
    vector<vector<int>> ans;
    vector<int> sa;
    int cs = 0;
    RLPWS(A, cs, ans, sa, B);
    return ans;
}
