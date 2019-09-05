vector<vector<int>> ans;
void right_rotate(vector<int> &s, int l, int r)
{
    if (l == r)
        return;
    char c = s[r];
    for (int i = l; i <= r; i++)
    {
        char temp = s[i];
        s[i] = c;
        c = temp;
    }
}
void left_rotate(vector<int> &s, int l, int r)
{
    if (l == r)
        return;
    char c = s[l];
    for (int i = r; i >= l; i--)
    {
        char temp = s[i];
        s[i] = c;
        c = temp;
    }
}
void permute_lexi(vector<int> &s, int l, int r)
{
    if (l == r)
        // cout<<s<<"\n";
        ans.push_back(s);
    else
    {
        for (int i = l; i <= r; i++)
        {
            // right_rotate(s, l,i);
            swap(s[l], s[i]);
            permute_lexi(s, l + 1, r);
            // left_rotate(s, l, i);
            swap(s[l], s[i]);
        }
    }
}
vector<vector<int>> Solution::permute(vector<int> &A)
{
    ans.clear();
    permute_lexi(A, 0, A.size() - 1);
    return ans;
}
