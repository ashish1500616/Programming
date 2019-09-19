#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &A)
{
    int n = int(A.size());
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]);
        }
    }
}

int main()
{
    vector<int> A = {1, 7, 2, 5, 2, 3, 9};
    bubble_sort(A);

    for (auto i : A)
        cout << i << " ";
}