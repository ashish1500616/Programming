#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &A)
{
    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j > -1 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[++j] = key;
    }
}

int main()
{
    vector<int> A = {1, 7, 2, 5, 2, 3, 9};
    insertion_sort(A);
    for (auto i : A)
        cout << i << " ";
}