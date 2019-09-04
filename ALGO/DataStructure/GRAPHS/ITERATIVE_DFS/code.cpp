#include <bit/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    stack<int> S;
    bool *visited;

public:
    Graph(int V_)
    {
        V = V_;
        adj = new list<int>[V];
        visited = new bool[V];
        memset(visited, false, sizeof visited);
    }
    void addEdge(int src, int dest)
    {
        adj[src].push_back(dest);
    }
    void DFS(int src)
    {
        cout << src << " ";
        visited[src] = true;
        for (auto it : adj[src])
        {
            if (!visited[it])
            {
                DFS(it);
            }
        }
        I
    }
};

int main()
{
}