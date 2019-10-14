/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Function To Check If Both The Node Are Present IN the tree or not.
void find(TreeNode *A, int B, int C, int &findB, int &findC)
{
    if (A == nullptr)
        return;
    if (A->val == B)
        findB = 1;
    if (A->val == C)
        findC = 1;
    find(A->left, B, C, findB, findC);
    find(A->right, B, C, findB, findC);
    return;
}

// Function to check if a single node is present in the linked list or not.

bool find(TreeNode *A, int value)
{
    if (A == nullptr)
        return false;
    if (A->val == value)
    {
        return 1;
    }
    return find(A->left, value) || find(A->right, value);
}

int LCA(TreeNode *A, int B, int C)
{
    if (A == nullptr)
    {
        return -1;
    }
    if (A->val == B)
        return B;
    if (A->val == C)
        return C;
    int ltr = LCA(A->left, B, C);
    int rtr = LCA(A->right, B, C);
    if (ltr == -1 && rtr == -1)
        return -1;
    if (ltr != -1 && rtr != -1)
        return A->val;
    if (rtr != -1)
    {
        return rtr;
    }
    if (ltr != -1)
    {
        return ltr;
    }
}

int Solution::lca(TreeNode *A, int B, int C)
{
    int findB = 0;
    int findC = 0;
    find(A, B, C, findB, findC);
    int ans = -1;
    // if (find(A, B) && find(A, C))
    if (findB && findC)
    {
        ans = LCA(A, B, C);
    }
    return ans;
}
