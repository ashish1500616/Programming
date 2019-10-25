// Approach 1. Using Hashing and Tokenization.
void tokenize(string s, map<string, int> &t)
{
    stringstream o(s);
    string temp;
    while (getline(o, temp, '_'))
    {
        if (t.count(temp) == 0)
            t.insert({temp, 1});
    }
}
int tokenizeArray(string s, map<string, int> &good)
{
    int goodC = 0;
    stringstream o(s);
    string temp;
    while (getline(o, temp, '_'))
    {
        if (good.count(temp) != 0)
            goodC++;
    }
    return goodC;
}
bool mycomparator(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return (a.first < b.first);
    }
    return (a.first > b.first);
}
vector<int> Solution::solve(string A, vector<string> &B)
{
    map<string, int> mp;
    vector<pair<int, int>> a;
    tokenize(A, mp);
    int i = 0;
    for (int x = 0; x < B.size(); x++)
    {
        int gc = tokenizeArray(B[x], mp);
        a.push_back({gc, x});
    }
    stable_sort(a.begin(), a.end(), mycomparator);
    vector<int> ans;
    for (auto x : a)
    {
        // cout<<x.first<<" "<<x.second<<"\n";
        ans.push_back(x.second);
    }
    return ans;
}



//  Approach 2: Using Trie.