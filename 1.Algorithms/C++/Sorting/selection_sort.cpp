#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &A)
{
    int n = A.size();
    int min_index;
    for (int i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min_index])
            {
                min_index = j;
            }
        }
        swap(A[i], A[min_index]);
    }
}

int main()
{
    vector<int> A = {1, 7, 2, 5, 2, 3, 9};
    selection_sort(A);
    for (auto i : A)
        cout << i << " ";
}