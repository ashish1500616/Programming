/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void findLongestConsecutiveSeq(TreeNode *A, int expected, int current, int &ans)
{
    if (A == nullptr)
        return;
    if (A->val == expected)
    {
        ++current;
    }
    else
    {
        current = 1;
    }
    ans = max(ans, current);
    findLongestConsecutiveSeq(A->left, A->val + 1, current, ans);
    findLongestConsecutiveSeq(A->right, A->val + 1, current, ans);
}
int Solution::solve(TreeNode *A)
{
    int ans = 0;
    findLongestConsecutiveSeq(A, (A->val), 0, ans);
    return ans;
}
