// # KOSARAJUs ALGORITHM FOR STRONGLY CONNECTED GRAPHS

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V_)
    {
        this->V = V_;
        adj = new list<int>[V];
    }
    void addEdge(int src, int dest)
    {
        adj[src].push_back(dest);
    }
    void FillStackOrder(int v, bool *visited, stack<int> &Stack)
    {
        visited[v] = true;
        for (auto it : adj[v])
        {
            if (!visited[it])
            {
                FillStackOrder(it,visited, Stack);
            }
        }
        Stack.push(v);
    }
    Graph getTranspose()
    {
        Graph g(V);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                g.adj[it].push_back(i);
            }
        }
        return g;
    }
    void DFS(int v, bool *visited)
    {
        visited[v] = true;
        cout << v << " ";
        for (auto it : adj[v])
        {
            if (!visited[it])
            {
                DFS(it, visited);
            }
        }
    }
    void printStronglyConnected()
    {
        stack<int> Stack;
        bool *visited = new bool[V];
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                FillStackOrder(i,visited,Stack);
            }
        }
        Graph gr = getTranspose();
        memset(visited, 0, sizeof visited);
        while (Stack.empty() == false)
        {
            int v = Stack.top();
            Stack.pop();
            if (!visited[v])
            {
                gr.DFS(v, visited);
                cout << endl;
            }
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(1, 0);

    g.addEdge(0, 2);

    g.addEdge(2, 1);

    g.addEdge(0, 3);

    g.addEdge(3, 4);

    cout << "Following are strongly connected components in "

            "given graph \n"; 

    g.printStronglyConnected();
    return 0;
}