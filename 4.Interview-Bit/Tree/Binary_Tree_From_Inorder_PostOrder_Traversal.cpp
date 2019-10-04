/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int search(vector<int> &A, int start, int end, int val)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if (A[i] == val)
            break;
    }
    return i;
}
TreeNode *buildUtil(vector<int> &A, vector<int> &B, int startRange, int endRange, int &parentIndex)
{
    if (startRange > endRange)
    {
        return nullptr;
    }
    TreeNode *node = new TreeNode(B[parentIndex--]);
    if (startRange == endRange)
    {
        return node;
    }
    int index = search(A, startRange, endRange, node->val);
    node->right = buildUtil(A, B, index + 1, endRange, parentIndex);
    node->left = buildUtil(A, B, startRange, index - 1, parentIndex);
    return node;
}
TreeNode *Solution::buildTree(vector<int> &A, vector<int> &B)
{
    int n = B.size();
    int parentIndex = n - 1;
    TreeNode *root = buildUtil(A, B, 0, n - 1, parentIndex);
    return root;
}
