#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    int *visited;
    int *level;

public:
    Graph(int V_)
    {
        V = V_;
        adj = new list<int>[V];
        visited = new int[V];
        memset(visited, false, sizeof visited);
        level = new int[V];
    }
    void addEdge(int src, int dest)
    {
        adj[src].push_back(dest);
    }
    int BFS(int src, int l)
    {
        visited[src] = true;

        list<int> queue;
        level[src] = 0;
        queue.push_back(src);
        while (!queue.empty())
        {
            int s = queue.front();
            queue.pop_front();
            for (auto it : adj[s])
            {
                if (!visited[it])
                {
                    level[it] = level[s] + 1;
                    visited[it] = true;
                    queue.push_back(it);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (level[i] == l)
                count++;
        }
        return count;
    }
};
int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    int level = 2;

    cout << g.BFS(0, level)<<"\n";

    return 0;
}