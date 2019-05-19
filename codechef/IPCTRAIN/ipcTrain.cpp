#include <bits/stdc++.h>
using namespace std;

void percolateDown(vector<pair<int, int>> &v, int first)
{
    int left = 2 * first + 1;
    int right = 2 * right + 2;
    int largest = first;
    int l = v.size();
    if (left < l && v[left].second > v[largest].second)
    {
        largest = left;
    }
    if (right < l && v[right].second > v[largest].second)
    {
        largest = right;
    }
    if (largest != first)
    {
        swap(v[largest], v[first]);
        percolateDown(v, largest);
    }
}

int parent(int index)
{
    return ((index - 1) * 1.0) / 2;
}
void percolateUp(vector<pair<int, int>> &v, int index)
{
    while (index != 0 and v[parent(index)] < v[index])
    {
        swap(v[index], v[parent(index)]);
        index = parent(index);
    }
}
void insertData(vector<pair<int, int>> &v, pair<int, int> data)
{
    v.emplace_back(data);
    percolateUp(v, int(v.size()) - 1);
}
pair<int, int> getMax(vector<pair<int, int>> &v)
{
    pair<int, int> val;
    val = v[0];
    v[0] = v[int(v.size()) - 1];
    percolateDown(v, 0);
    return val;
}
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        vector<pair<int, int>> heap_arr;
        int n, d;
        cin >> n >> d;
        vector<vector<pair<int, int>>> hash(d, vector<pair<int, int> >());
        while (n--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            hash[a].emplace_back(make_pair(b, c));
        }
        int ds = 1;
        while (ds <= d)
        {
            if (int(hash[ds].size()) > 0)
            {
                for (int it = 0; it < hash[ds].size(); it++)
                {
                    heap_arr.emplace_back(hash[ds][it]);
                }
            }
            if (heap_arr.size() > 0)
            {
                pair<int, int> data;
                data = getMax(heap_arr);
                data.first =data.first - 1;
                if (data.first > 0)
                {
                    insertData(heap_arr, data);
                }
            }
            ds += 1;
        }
        int sum = 0;
        for (auto it : heap_arr)
        {
            sum += it.first * it.second;
        }
        cout << sum << endl;
    }
}