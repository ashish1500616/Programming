#include <bits/stdc++.h>
using namespace std;

#define vput(x)         \
    for (auto it : (x)) \
    cout << it << " "

//  for (auto it : (c)) {                                                        \
//     cout << it << " ";                                                         \
//   }
int a[5] = {5, 2, 1, 4, 3};
int bit_tree[6] = {0};
void update(int index, int val, int n)
{
    while (index < n)
    {

        bit_tree[index] += val;
        index += index & (-index);
    }
}
int query(int index)
{
    int sum = 0;
    while (index > 0)
    {
        sum += bit_tree[index];
        index -= (index & (-index));
    }
    return sum;
}
int main()
{
    int ans = 0, x;
    for (int i = 4; i >= 0; i--)
    {
        // cout<<a[i];
        x = query(a[i] - 1);
        cout << x << endl;
        ans += x;
        cout << "before"
             << "\n";
        vput(bit_tree);
        cout << endl;
        update(a[i], 1, 5);
        cout << "After"
             << "\n";
        vput(bit_tree);
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}
