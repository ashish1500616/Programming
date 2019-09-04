#include <bits/stdc++.h>
using namespace std;

vector<int> smallerElementFromLeft(vector<int> A, int n = 1)
{
    stack<int> s;
    int l = int(A.size());
    vector<int> v;
    if (n)
    {
        v.clear();
        for (int i = 0; i < l; i++)
        {
            while (!s.empty() && A[s.top()] >= A[i])
            {
                s.pop();
            }
            if (s.empty())
                v.emplace_back(-1);
            else
                v.emplace_back(s.top());
            s.push(i);
        }
    }
    else
    {
        v.clear();
        for (int i = l - 1; i >= 0; i--)
        {
            while (!s.empty() && A[s.top()] >= A[i])
            {
                s.pop();
            }
            if (s.empty())
                v.emplace_back(-1);
            else
                v.emplace_back(s.top());
            s.push(i);
        }
    }
    return v;
}
int largestRectangleArea(vector<int> &A)
{
    int l = int(A.size());
    if (l == 1)
        return A[0];
    vector<int> lm = smallerElementFromLeft(A, 1);
    vector<int> rm = smallerElementFromLeft(A, 0);
    vector<int> ma(l, 0);

    // for (auto x: lm)
    // {
    //     cout<<x<<endl;
    // }
    // cout<<"---------\n";
    // for (auto x: rm)
    // {
    //     cout<<x<<endl;
    // }
    // cout<<"---------\n";
    int max_v = INT_MIN;
    for (int i = 0; i < l; i++)
    {
        // cout << lm[i] << "  " << rm[l - i - 1] << endl;
        if (lm[i] < 0 && rm[l - i - 1] < 0)
        {
            ma[i] = A[i] * l;
        }
        else if (lm[i] >= 0 && rm[l - i - 1] >= 0)
        {
            ma[i] = A[i] * abs(rm[l - i - 1] - lm[i] - 1);
        }
        else if (lm[i] < 0 && rm[l - i - 1] >= 0)
        {
            ma[i] = A[i] * abs(rm[l - i - 1]);
        }
        else if (lm[i] >= 0 && rm[l - i - 1] < 0)
        {
            ma[i] = A[i] * ((i - lm[i]) + (l - i - 1));
        }
        max_v = max(max_v, ma[i]);
    }
    cout << "---------\n";
    for (auto x : ma)
    {
        cout << x << endl;
    }
    cout << "---------\n";
    for (auto x : ma)
    {
        if (x > max_v)
            max_v = x;
    }

    return max_v;
}

int main()
{
    // vector<int> A = {47, 69, 67, 97, 86, 34, 98, 16, 65, 95, 66, 69, 18, 1, 99, 56, 35, 9, 48, 72, 49, 47, 1, 72, 87, 52, 13, 23, 95, 55, 21, 92, 36, 88, 48, 39, 84, 16, 15, 65, 7, 58, 2, 21, 54, 2, 71, 92, 96, 100, 28, 31, 24, 10, 94, 5, 81, 80, 43, 35, 67, 33, 39, 81, 69, 12, 66, 87, 86, 11, 49, 94, 38, 44, 72, 44, 18, 97, 23, 11, 30, 72, 51, 61, 56, 41, 30, 71, 12, 44, 81, 43, 43, 27};
    vector<int> A = {51, 33};
    // vector<int> A = {90, 58, 69, 70, 82, 100, 13, 57, 47, 18};
    cout << largestRectangleArea(A) << "\n";
    return 0;
}