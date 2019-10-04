/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Accepted Approach
vector<vector<int>> Solution::verticalOrderTraversal(TreeNode *A)
{

    vector<vector<int>> ans;
    if (A == NULL)
        return ans;
    queue<pair<TreeNode *, int>> q;
    q.push({A, 0});

    map<int, vector<int>> mp;
    while (!q.empty())
    {
        pair<TreeNode *, int> temp = q.front();
        q.pop();

        if (temp.first->left)
        {
            q.push({temp.first->left, temp.second - 1});
        }
        if (temp.first->right)
        {
            q.push({temp.first->right, temp.second + 1});
        }

        mp[temp.second].push_back(temp.first->val);
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

// 2nd Approach
// void VerticalOrderTraversal(map<int, vector<int>> &m, TreeNode *node, int hd)
// {
//     if (node == nullptr)
//         return;
//     m[hd].push_back(node->val);
//     VerticalOrderTraversal(m, node->left, hd - 1);
//     VerticalOrderTraversal(m, node->right, hd + 1);
// }
// vector<vector<int>> Solution::verticalOrderTraversal(TreeNode *A)
// {
//     map<int, vector<int>> m;
//     VerticalOrderTraversal(m, A, 0);
//     vector<vector<int>> ans;
//     for (auto it : m)
//     {
//         cout << it.first << "\n";
//         for (auto x : it.second)
//         {
//             cout << x << " ";
//         }
//         cout << "\n";
//         ans.push_back(it.second);
//     }
//     return ans;
// }

// 1st Approach
// void findMinMax(TreeNode* Node , int& min_n ,int& max_n,int curr)
// {
//     if (Node == nullptr)
//     {
//         return;
//     }
//     else
//     {
//         max_n=max(curr,max_n);
//         min_n=min(curr,min_n);
//         //  cout<<min_n<<" "<<max_n<<"\n";
//         findMinMax(Node->left,min_n,max_n,curr-1);
//         findMinMax(Node->right,min_n,max_n,curr+1);
//     }
// }
// void printVerticalOrder( vector<int>& A,TreeNode* Node,int lineNo, int curr )
// {
//     if(Node == nullptr)
//     {
//         return;
//     }
//     if(lineNo == curr)
//     {
//         A.push_back(Node->val);
//         // cout<<Node->val<<"\n";
//     }
//     printVerticalOrder(A,Node->left,lineNo,curr-1);
//     printVerticalOrder(A,Node->right,lineNo,curr+1);
// }
// vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
//     int min=0,max=0;
//     findMinMax(A,min,max,0);
//     // cout<<min<<" "<<max<<"\n";
//     vector<vector<int> > ans;
//     for(int i=min;i<=max;i++)
//     {
//         vector<int> sub;
//         printVerticalOrder(sub,A,i,0);
//         ans.push_back(sub);
//     }
//     return ans;
// }
