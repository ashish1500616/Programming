#include <bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &A, int pos)
{
    int n = A.size();
    int r = 10;
    vector<int> cnt(r);
    vector<int> B(n);

    for (int i = 0; i < n; i++)
    {
        cnt[((A[i] / pos) % 10)]++;
    }
    for (int i = 1; i < r; i++)
    {
        cnt[i] = cnt[i] + cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        B[--cnt[(A[i] / pos) % 10]] = A[i];
    }
    for (int i = 0; i < n; i++)
    {
        A[i] = B[i];
    }
}

void radix_sort(vector<int> &A)
{
    int max_value = *max_element(A.begin(), A.end());
    for (int i = 1; (max_value / i) > 0; i *= 10)
    {
        count_sort(A, i);
    }
}

int main()
{
    vector<int> A = {1, 7, 2, 5, 10, 2, 3, 9};
    radix_sort(A);
    for (auto i : A)
        cout << i << " ";
}

// TC = o( d * ( n + k ))