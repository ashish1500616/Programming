#include <bits/stdc++.h>
using namespace std;

class Graph
{
    list<int> *adj;
    int V;

public:
    Graph(int V_)
    {
        V = V_;
        adj = new list<int>[V];
    }
    void addEdge(int src, int dest)
    {
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }
    bool DFS(int v, vector<bool> &visited, vector<int> &Degree, int k)
    {
        visited[v] = true;
        for (auto it : adj[v])
        {
            if (Degree[v] < k)
            {
                Degree[it]--;
            }
            if (!visited[it])
            {
                if (DFS(it, visited, Degree, k))
                    Degree[v]--;
            }
        }
        return (Degree[v] < k);
    }
    void printK(int k)
    {
        vector<bool> visited(V, false);
        vector<int> Degree(V, 0);
        int minDegree = INT_MAX;
        int sv;
        for (int i = 0; i < V; i++)
        {
            Degree[i] = adj[i].size();
            if (Degree[i] < minDegree)
            {
                minDegree = Degree[i];
                sv = i;
            }
        }
        DFS(sv, visited, Degree, k);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFS(i, visited, Degree, k);
            }
        }
        cout << "K cores" << endl;
        for (int i = 0; i < V; i++)
        {
            if (Degree[i] >= k)
            {
                cout << "[" << i << "]";
                for (auto it : adj[i])
                {
                    if (Degree[it] >= k)
                    {
                        cout << "-->" << it;
                    }
                }
                cout << "\n";
            }
        }
    }
};
int main()

{

    int k = 3;

    Graph g1(9);

    g1.addEdge(0, 1);

    g1.addEdge(0, 2);

    g1.addEdge(1, 2);

    g1.addEdge(1, 5);

    g1.addEdge(2, 3);

    g1.addEdge(2, 4);

    g1.addEdge(2, 5);

    g1.addEdge(2, 6);

    g1.addEdge(3, 4);

    g1.addEdge(3, 6);

    g1.addEdge(3, 7);

    g1.addEdge(4, 6);

    g1.addEdge(4, 7);

    g1.addEdge(5, 6);

    g1.addEdge(5, 8);

    g1.addEdge(6, 7);

    g1.addEdge(6, 8);

    g1.printK(k);

    cout << endl
         << endl;

    Graph g2(13);

    g2.addEdge(0, 1);

    g2.addEdge(0, 2);

    g2.addEdge(0, 3);

    g2.addEdge(1, 4);

    g2.addEdge(1, 5);

    g2.addEdge(1, 6);

    g2.addEdge(2, 7);

    g2.addEdge(2, 8);

    g2.addEdge(2, 9);

    g2.addEdge(3, 10);

    g2.addEdge(3, 11);

    g2.addEdge(3, 12);

    g2.printK(k);

    return 0;
}