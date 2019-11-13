int decodeVariations(const string &S)
{
    // your code goes here
    int N = S.size();
    vector<int> dp(N + 1, 0);
    dp[N] = 1; // base case
    for (int i = N - 1; i >= 0; i--)
    {
        if (S[i] != '0')
            dp[i] = dp[i + 1];
        //check two digit can be number
        if (i < N - 1)
        {
            int k = stoi(S.substr(i, 2));
            if (1 <= k && k <= 26)
                dp[i] += dp[i + 2];
        }
    }
    return dp[0];
}

int decodeVariations(const string &S)
{
    // your code goes here
    int N = S.size();
    vector<int> dp(3, 0);
    dp[N % 3] = 1; // base case
    for (int i = N - 1; i >= 0; i--)
    {
        if (S[i] != '0')
            dp[i % 3] = dp[(i + 1) % 3];
        //check two digit can be number
        if (i < N - 1)
        {
            int k = stoi(S.substr(i, 2));
            if (1 <= k && k <= 26)
                dp[i % 3] += dp[(i + 2) % 3];
        }
    }
    return dp[0];
}

#import <iostream>
#import <string>
#import <vector>

using namespace std;
/*
           v
source ABCDEFG
target ABDFFGH
              ^
            A B D F  F G H
         A  1 
         B    1
         C     -1
         D      1
         E        -1
         F           1
         G              
dp[i][j] = 
*/
//return minimum edit distance of soruce(i...end) and tareget(j..end)
int dfs(int i, int j, string &source, string &target, vector<vector<int>> &dp)
{
    if (i == source.length() && j == target.length())
        return 0; // its over basecase
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == source.length())
    {
        return dp[i][j] = 1 + dfs(i, j + 1, source, target);
    }
    if (j == target.length())
    {
        return dp[i][j] = 1 + dfs(i + 1, j, source, target);
    }
    if (source[i] == target[j])
    {
        return dp[i][j] = dfs(i + 1, j + 1, source, target);
    }
    else
    {
        return dp[i][j] = 1 + min(dfs(i + 1, j, source, target), dfs(i, j + 1, source, target));
    }
}

vector<string> diffBetweenTwoStrings(const string &source, const string &target)
{
    // your code goes here
    vector<vector<int>> dp(source.length(), vector<int>(target.length(), -1));
    dfs(0, 0, source, target, dp);
    vector<string> ans;
    int i = 0, j = 0;
    while (i < source.length() && j < target.length())
    {
        if (i == source.length())
        {
            ans.push_back("+" + target[j]); // add from target
            j++;
        }
        if (j == target.length())
        {
            ans.push_back("-" + source[i]); //remove from source
            i++;
        }
        if (source[i] == target[j])
        {
            ans.push_back(source[i]); // just add char
            i++, j++;
        }
        else
        {
            if (dp[i + 1][j] <= dp[i][j + 1])
            {
                ans.push( array.stringh_back("-" + source[i]);
                i++;
            }
            else
            {
                ans.push_back("+" + target[j]);
                j++;
                diffBetweenTwoStrings
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}
