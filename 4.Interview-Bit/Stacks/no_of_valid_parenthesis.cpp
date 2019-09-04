#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string A)
{
    stack<int> s;
    s.push(-1);
    int c = 0;
    for (int i = 0; i < A.length(); i++)
    {
        // cout<<A[i]<<endl;
        if (A[i] == ')' && !s.empty())
        {
            s.pop();
            if (!s.empty())
            {
                c = max(c, i - s.top());
            }
            else
            {
                s.push(i);
            }
        }
        else if (A[i] == '(')
        {
            s.push(i);
        }
    }
}
int main()
{
    // string c=")()())";
    string c = ")()))(())((())))))())()(((((())())((()())(())((((())))())((()()))(()(((()()(()((()()))(())()))(((";
    cout << longestValidParentheses(c);
    return 0;
}