
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;
typedef long long int ll;

void dijkstra(Graph &g, int s, vector<int> &distance, vector<int> &shortest_path)
{
    int n = g.size();
    distance.assign(n, INT_MAX);
    distance[s] = 0;
    shortest_path.assign(n, -1);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(make_pair(0, s));

    while (!q.empty())
    {
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        if (d != distance[u])
            continue;
        for (int i = 0; i < (int)g[u].size(); i++)
        {
            int v = g[u][i].first;
            int nprio = distance[u] + g[u][i].second;
            if (distance[v] > nprio)
            {
                distance[v] = nprio;
                shortest_path[v] = u;
                q.push(make_pair(nprio, v));
            }
        }
    }
}

int main(void)
{
    Graph g(3);
    g[0].push_back(make_pair(1, 10));
    g[1].push_back(make_pair(2, -5));
    g[0].push_back(make_pair(2, 8));

    // distance is for storing the minimum distance from the source node.
    vector<int> distance;
    // shortest_path is for storing the node through which the distance is minimum.
    vector<int> shortest_path;

    dijkstra(g, 0, distance, shortest_path);

    for (int i = 0; i < distance.size(); i++)
        cout << distance[i] << endl;
}