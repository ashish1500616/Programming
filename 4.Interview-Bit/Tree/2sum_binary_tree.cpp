/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void InorderTraversal(TreeNode *A, vector<int> &s)
{
    if (A == nullptr)
        return;
    InorderTraversal(A->left, s);
    s.push_back(A->val);
    InorderTraversal(A->right, s);
}
bool check(vector<int> A, int B)
{
    int i = 0;
    int j = A.size() - 1;
    while (i < j)
    {
        int sum = A[i] + A[j];
        if (sum == B)
            return 1;
        if (sum > B)
        {
            --j;
        }
        else
        {
            ++i;
        }
    }
    return 0;
}
int Solution::t2Sum(TreeNode *A, int B)
{
    vector<int> s;
    int ans = 0;
    InorderTraversal(A, s);
    ans = check(s, B);
    return ans;
}
