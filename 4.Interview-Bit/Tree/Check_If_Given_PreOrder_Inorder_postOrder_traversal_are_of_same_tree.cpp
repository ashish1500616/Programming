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
void PreOrder(TreeNode *A, vector<int> &pre)
{
    if (A == nullptr)
    {
        return;
    }
    pre.emplace_back(A->val);
    PreOrder(A->left, pre);
    PreOrder(A->right, pre);
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int n = B.size();
    int parentIndex = n - 1;
    // B is the Inorder TraverSal of A Binary Tree
    // C is the PostOrder Traversal of a Binary Tree
    // A is the Pre Order Traversal of a Binary Tree.
    
    // Time Complexity ------- O(n^2) for Building Tree From Inorder Or Postorder
    TreeNode *root = buildUtil(B, C, 0, n - 1, parentIndex);
    vector<int> preorder;
    PreOrder(root, preorder);

    return (A == preorder) ? 1 : 0;
}

// On Using Iterative Fails On Memory .
// void PreOrder(TreeNode * A,vector<int>&Pre)
// {
//     if(A==nullptr)
//     return;
//     stack<TreeNode*> s;
//     s.push(A);
//     while(!s.empty())
//     {
//         Pre.push_back(s.top()->val);
//         if(s.top()->right)
//         s.push(s.top()->right);
//         if(s.top()->left)
//         s.push(s.top()->left);
//         s.pop();
//     }

// }