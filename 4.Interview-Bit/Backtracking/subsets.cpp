void ss(vector<int> &A, vector<vector<int>> &ans, vector<int> &subs, int index)
{
    ans.push_back(subs);
    for (int i = index; i < int(A.size()); i++)
    {
        subs.push_back(A[i]);
        ss(A, ans, subs, i + 1);
        subs.pop_back();
    }
    return;
}

vector<vector<int>> Solution::subsets(vector<int> &A)
{
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    // Backtracking Approach
    vector<int> subs;
    ss(A, ans, subs, 0);
    return ans;
}

// int sz = A.size();
// Iterative Approach
// int no = pow(2, sz);
// for(int i=0;i<no;i++)
// {
//     vector<int> ts;
//     for(int j=0;j<sz;j++)
//     {
//         if(i&(1<<j))
//         {
//             ts.push_back(A[j]);
//         }
//     }
//     ans.push_back(ts);
// }
// return ans;