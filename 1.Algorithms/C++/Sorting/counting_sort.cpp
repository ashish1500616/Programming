#include <bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &A)
{
    int n = int(A.size());
    int max_value = *max_element(A.begin(), A.end());
    vector<int> cnt(max_value + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cnt[A[i]]++;
    }
    int k = 0;
    for (int i = 0; i <= max_value; i++)
    {
        while (cnt[i]--)
        {
            A[k++] = i;
        }
    }
}

int main()
{
    vector<int> A = {1, 7, 2, 5, 10, 2, 3, 9};
    count_sort(A);
    for (auto i : A)
        cout << i << " ";
    cout<<"\n";
}
