#include <bits/stdc++.h>
using namespace std;

void stable_selection_sort(vector<int> &A)
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
        int key = A[min_index];
        while (min_index > i)
        {
            A[min_index] = A[min_index - 1];
            --min_index;
        }
        A[i] = key;
    }
}

int main()
{
    vector<int> A = {1, 7, 2, 5, 2, 3, 9};
    stable_selection_sort(A);
    for (auto i : A)
        cout << i << " ";
}
