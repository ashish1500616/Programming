#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    int *visited;

public:
    int path;
    Graph(int V_)
    {
        V = V_;
        adj = new list<int>[V];
        visited = new int[V];
        memset(visited, false, sizeof visited);
        path = 0;
    }
    void addEdge(int src, int dest)
    {
        adj[src].push_back(dest);
    }
    void countpaths(int src, int destination)
    {

        visited[src] = true;
        if (src == destination)
            path++;
        else
        {
            for (auto it : adj[src])
            {
                if (!visited[it])
                {
                    countpaths(it, destination);
                }
            }
        }
        visited[src] = false;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);

    int s = 2, d = 3;
    g.countpaths(s, d);
    cout << g.path << endl;
    return 0;
}