// Range Minimum Query
// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/


// SAMPLE INPUT 
// 5 5
// 1 5 2 4 3
// q 1 5
// q 1 3
// q 3 5
// u 3 6
// q 1 5
// SAMPLE OUTPUT 
// 1
// 1
// 2
// 1
#include <bits/stdc++.h>
using namespace std;

int *tree = NULL;
int *arr = NULL;

void build_tree(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build_tree(2 * node, start, mid);
        build_tree(2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}
int query_node(int node, int start, int end, int l, int r)
{
    if (start > end || r < start || end < l)
    {
        return INT_MAX;
    }
    if (start >= l && end <= r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int m1, m2;
    m1 = query_node(2 * node, start, mid, l, r);
    m2 = query_node(2 * node + 1, mid + 1, end, l, r);
    return min(m1, m2);
}
void update_node(int node, int start, int end, int l, int r)
{
    if (start > end || l < start || l > end)
        return;
    if (start == end)
    {
        arr[l] = r;
        tree[node] = r;
        return;
    }
    int mid = (start + end) / 2;
    update_node(2 * node, start, mid, l, r);
    update_node(2 * node + 1, mid + 1, end, l, r);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
void printArr(int n)
{
    for (int i = 0; i < 4 * n + 1; i++)
    {
        if (tree[i] != 0)
            cout << tree[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int n, q;
    cin >> n >> q;
    arr = new int[n];
    tree = new int[4 * n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build_tree(1, 0, n - 1);
    while (q--)
    {
        char op;
        int l, r;
        cin >> op >> l >> r;
        if (op == 'q')
        {
            int mval = query_node(1, 0, n - 1, l - 1, r - 1);
            cout << mval << "\n";
        }

        else if (op == 'u')
        {
            update_node(1, 0, n - 1, l - 1, r);
        }
    }
    return 0;
}