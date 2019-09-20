#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &A, int l, int r)
{
    int n = int(A.size());
    int pivot = r-1;
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (A[j] <A[pivot])
        {
            swap(A[++i], A[j]);
        } 
    }
    swap(A[++i], A[pivot]);
    return i;
}

void quickSort(vector<int> &A, int l, int h)
{
    if (l < h)
    {
        int p = partition(A, l, h);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, h);
    }
}

int main()
{
    vector<int> A = {1, 7, 2, 5, 2, 3, 9};
    int n = int(A.size());
    quickSort(A, 0, n);
    for (auto i : A)
        cout << i << " ";
}