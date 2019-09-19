#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[i + l];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = A[j + m + 1];
    }
    int i, j, k;
    i = j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k++] = L[i++];
        }
        else
        {
            A[k++] = R[j++];
        }
    }
    while (i < n1)
    {
        A[k++] = L[i++];
    }
    while (j < n2)
    {
        A[k++] = R[j++];
    }
}

void merge_sort(vector<int> &A, int l, int r)
{
    if (l < r)
    {
        int mid = l + ((r - l) >> 1);
        merge_sort(A, l, mid);
        merge_sort(A, mid + 1, r);
        merge(A, l, mid, r);
    }
}

int main()
{
    vector<int> A = {1, 7, 2, 5, 2, 3, 9};
    int n = int(A.size());
    merge_sort(A, 0, n - 1);
    for (auto i : A)
        cout << i << " ";
}