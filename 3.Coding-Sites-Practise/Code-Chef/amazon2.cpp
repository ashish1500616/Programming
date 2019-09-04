#include <bits/stdc++.h>
using namespace std;

vector<bool> v;
vector<vector<int>> g;
vector<set<int>> s;

void bfs(int u, int *arr)
{
    queue<int> q;
    q.push(u);
    v[u] = 1;
    int d = 0;
    s[d].insert(arr[u]);
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        d++;
        // cout << f << " ";
        //enqueue all the adjacent node to f
        for (auto i = g[f].begin(); i != g[f].end(); i++)
        {
            if (!v[*i])
            {
                q.push(*i);
                v[*i] = 1;
                s[d].insert(arr[*i]);
            }
        }
    }
}

void addEdge(int a, int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

int main()
{
    int n, q;
    cin >> n >> q;
    g.assign(n + 1, vector<int>());
    v.assign(n + 1, 0);
    s.assign(n + 1, set<int>());
    int *arr = new int[n + 1];
    for (int i = 0; i < n; i++)
        cin >> arr[i + 1];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        addEdge(x, y);
    }
    bfs(1, arr);
    while (q--)
    {
        int l, x;
        cin >> l >> x;
        l=l % n;
        if (lower_bound(s[l].begin(), s[l].end(), x) != s[l].end())
        {
            cout << *lower_bound(s[l].begin(), s[l].end(), x);
        }
        else
        {
            cout <<-1<< endl;
        }
    }
}

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    set<int> s;
    int n,q;
    cin>>n>>q;
    int *arr =new int[q];
    for (int i=0;i<q;i++)
    {
        int v;
        cin>>v;
        arr[i]=v;
    }
    for(int j=0;j<q;j++)
    {
        s.insert(arr[j]);
        ll r=1;
        set<int>::iterator p=s.begin();
        for(set<int>::iterator it=++s.begin();it!=s.end();it++)
        {
            r+=*(p++)*1L+*(it)*1L;
        }
        r+=n*1L;
        cout<<r<<endl;
    }
}