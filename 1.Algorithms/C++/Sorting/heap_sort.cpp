#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &A, int n, int index)
{
    int largest = index;       // Index
    int left = 2 * index + 1;  // Left Node
    int right = 2 * index + 2; // Right Node

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != index)
    {
        swap(A[largest], A[index]);
        heapify(A, n, largest);
    }
}

void heap_Sort(vector<int> &A)
{
    int n = int(A.size());

    for (int i = (n >> 1) - 1; i >= 0; i--)
    {
        heapify(A, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

int main()
{
    vector<int> A = {1, 7, 2, 5, 2, 3, 9};
    heap_Sort(A);

    for (auto i : A)
        cout << i << " ";
}