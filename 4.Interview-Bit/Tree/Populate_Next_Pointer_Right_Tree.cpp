// TODO SOLVE USING O(1) --->   Space Complexity.
TreeLinkNode *nextRight(TreeLinkNode *current)
{
    TreeLinkNode *currNext = current->next;

    while (currNext)
    {
        if (currNext->left)
            return currNext->left;
        else if (currNext->right)
            return currNext->right;
        currNext = currNext->next;
    }
    return NULL;
}
void Solution::connect(TreeLinkNode *A)
{
    if (!A)
        return;
    A->next = NULL;
    while (A)
    {
        TreeLinkNode *B = A;
        while (B)
        {
            if (B->left)
            {
                if (B->right)
                    B->left->next = B->right;
                else
                    B->left->next = nextRight(B);
            }
            if (B->right)
                B->right->next = nextRight(B);

            B = B->next;
        }
        if (A->left)
            A = A->left;
        else if (A->right)
            A = A->right;
        else
            A = nextRight(A);
    }
}
// Approach 2 - TC(O(N))  , SC - (O(N))
// void connectTree(TreeLinkNode * A)
// {
//     queue<TreeLinkNode *> q;
//     q.push(A);
//     q.push(nullptr);
//     while (!q.empty())
//     {
//         TreeLinkNode *t = q.front();
//         q.pop();
//         if (t != nullptr)
//         {
//             t->next = q.front();
//             if (t->left)
//                 q.push(t->left);
//             if (t->right)
//                 q.push(t->right);
//         }
//         else if (!q.empty())
//             q.push(nullptr);
//     }
// }
// void Solution::connect(TreeLinkNode * A)
// {
//     connectTree(A);
// }

// Wrong Approach // fails
// /**
//  * Definition for binary tree with next pointer.
//  * struct TreeLinkNode {
//  *  int val;
//  *  TreeLinkNode *left, *right, *next;
//  *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
//  * };
//  */

// TreeLinkNode *findNext(TreeLinkNode *curr, TreeLinkNode *parent)
// {
//     if (curr == parent->right)
//     {
//         if (parent->next != nullptr)
//             parent = parent->next;
//         else
//             return nullptr;
//     }
//     while ((parent->left) || (parent->right))
//     {
//         if (parent->left && parent->left != curr)
//             return parent->left;
//         else if (parent->right && parent->right != curr)
//             return parent->right;
//         else if (parent->next)
//             parent = parent->next;
//     }
//     return nullptr;
// }
// void TreeTraversal(TreeLinkNode *A)
// {

//     TreeLinkNode *nnext = nullptr;
//     if (A->left)
//     {
//         nnext = findNext(A->left, A);
//         A->left->next = nnext;
//         // cout<<A->left->val<<" --> " <<nnext->val<<"\n";
//     }
//     if (A->right)
//     {
//         nnext = findNext(A->right, A);
//         A->right->next = nnext;
//         // cout<<A->right->val<<"----- >";
//         // if(nnext)
//         // {
//         //     cout<<nnext->val<<"\n";
//         // }
//         // else
//         // {
//         //     cout<<"null\n";
//         // }
//     }
//     if (A->left)
//         TreeTraversal(A->left);
//     if (A->right)
//         TreeTraversal(A->right);
// }
// void Solution::connect(TreeLinkNode *A)
// {
//     A->next = nullptr;
//     TreeTraversal(A);
// }
