string dupSubUtil(TreeNode *A, unordered_set<string> &subtrees)
{
    string s = "";
    if (A == nullptr)
    {
        return s + "$";
    }
    string lstr = dupSubUtil(A->left, subtrees);
    if (lstr == s)
        return s;

    string rstr = dupSubUtil(A->right, subtrees);
    if (rstr == s)
        return s;
    s = s + to_string(A->val) + lstr + rstr;
    if (s.size() > 3 && (subtrees.find(s) != subtrees.end()))
    {
        // cout<<s.size()<<"\n";
        return "";
    }
    subtrees.insert(s);
    return s;
}
int Solution::solve(TreeNode *A)
{
    unordered_set<string> subtrees;
    int ans = 0;
    if (dupSubUtil(A, subtrees) == "")
    {
        ans = 1;
    }
    // for(auto x= subtrees.begin();x!=subtrees.end();x++)
    // {
    //     cout<< *x << " \n";
    // }
    return ans;
}
