// TIME COMPLEXITY = O(E+V)
// SPACE COMPLEXITY = O(E+V)
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    bool *visited;

public:
    Graph(int V_)
    {
        V = V_;
        adj = new list<int>[V];
        visited = new bool[V];
    }
    void addEdge(int src, int dest)
    {
        adj[src].push_back(dest);
    }
    int DFS(int v)
    {
        // cout << v << " ";
        visited[v] = true;
        for (auto it : adj[v])
        {
            if (!visited[it])
            {
               DFS(it);
            }
        }
    }
    int FindMother()
    {
        memset(visited, false, sizeof visited);
        int sm;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFS(i);
                sm = i;
            }
        }
        memset(visited, false, sizeof visited);
        DFS(sm);
        for (int it = 0; it < V; it++)
        {
            if (visited[it] == false)
                return -1;
        }
        return sm;
    }
};
int main()
{
    Graph g(7);

    g.addEdge(0, 1);

    g.addEdge(0, 2);

    g.addEdge(1, 3);

    g.addEdge(4, 1);

    g.addEdge(6, 4);

    g.addEdge(5, 6);

    g.addEdge(5, 2);

    g.addEdge(6, 0);

    cout << "Mother of all the vertices\n"
         << g.FindMother()<<"\n";
}