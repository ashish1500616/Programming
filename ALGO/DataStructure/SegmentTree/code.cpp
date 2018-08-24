#include <bits/stdc++.h>
using namespace std;
int lazy[1000] = {0};
void build_tree(int *tree, int *arr, int index, int s, int e) {
  // Base Case
  if (s > e) {
    return;
  }
  // When node is a leaf node
  if (s == e) {
    tree[index] = arr[s];
    return;
  }
  int mid = (s + e) / 2;
  build_tree(tree, arr, 2 * index, s, mid);
  build_tree(tree, arr, 2 * index + 1, mid + 1, e);
  tree[index] = min(tree[2 * index], tree[(2 * index) + 1]);
}
int query(int *tree, int index, int qs, int qe, int s, int e) {
  if (qs > e || qe < s)
    return INT_MAX;
  if (s >= qs && e <= qe) {
    return tree[index];
  }
  int mid = (s + e) / 2;
  int leftAns = query(tree, 2 * index, qs, qe, s, mid);
  int rightAns = query(tree, 2 * index + 1, qs, qe, mid + 1, e);
  return min(leftAns, rightAns);
}
void updateNode(int *tree, int s, int e, int index, int i, int val) {
  if (i < s && i > e) {
    return;
  }
  if (s == e) {
    tree[index] = val;
  }
  int mid = (s + e) / 2;
  updateNode(tree, s, mid, 2 * index, i, val);
  updateNode(tree, mid, e, 2 * index + 1, i, val);
  tree[index] = min(tree[index * 2], tree[2 * index + 1]);
}
void updateRange(int *tree, int s, int e, int sr, int er, int index, int val) {
  if (sr > e || er < s) {
    return;
  }
  if (s == e) {
    tree[index] = val;
  }
  int mid = (s + e) / 2;
  updateRange(tree, s, mid, sr, er, 2 * index, val);
  updateRange(tree, mid + 1, e, sr, er, 2 * index + 1, val);
  tree[index] = min(tree[index * 2], tree[2 * index + 1]);
}
int lazy_query(int *tree, int index, int s, int e, int qs, int qe) {
  // Resolve Lazy
  if (lazy[index] != 0) {
    tree[index] += lazy[index];
    if (s != e) {
      lazy[2 * index] += lazy[index];
      lazy[2 * index + 1] += lazy[index];
    }
    lazy[index] = 0;
  }
  // No Overlap Case
  if (qs > e || qe < s)
    return INT_MAX;

  // Complete Overlap Case
  if (s >= qs && e <= qe) {
    return tree[index];
  }
  // Partial Overlap Case
  int mid = (s + e) / 2;
  int leftAns = lazy_query(tree, 2 * index, s, mid, qs, qe);
  int rightAns = lazy_query(tree, 2 * index + 1, mid + 1, e, qs, qe);
  return min(leftAns, rightAns);
}
void updateRangeLazy(int *tree, int *lazy, int index, int s, int e, int qs,
                     int qe, int inc) {
  // Resolve Lazy
  if (lazy[index] != 0) {
    tree[index] += lazy[index];
    if (s != e) {
      lazy[2 * index] += lazy[index];
      lazy[2 * index + 1] += lazy[index];
    }
    lazy[index] = 0;
  }
  // No Overlap Case
  if (qs > e || qe < s)
    return;
  // Complete Overlap Case
  if (s >= qs && e <= qe) {
    tree[index] += inc;
    if (s != e) {
      lazy[index * 2] += inc;
      lazy[index * 2 + 1] += inc;
    }
    return;
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int arr[5] = {1, 98, 17, 92, -1};
  int n = sizeof(arr) / sizeof(int);
  int *tree = new int[4 * n + 1];

  int index = 1;
  int s = 0, e = n - 1;
  build_tree(tree, arr, index, s, e);
  for (int i = 1; i < 10; i++) {
    cout << tree[i] << "\n";
  }

  // cout << "Query\n";
  // // cout << lazy_query(tree, index, 0, n - 1, 1, 2) << endl;
  int no;
  cin >> no;
  while (no--) {
    int a, b;
    cin >> a >> b;
    cout << "Query\n";
    int val = query(tree, 1, a, b, 0, n - 1);
    cout << val << endl;
    cout << "lazy query output" << endl;
    int lazy_val = lazy_query(tree, 1, 0, n - 1, a, b);
    cout << lazy_val << endl;
  }

  return 0;
}
