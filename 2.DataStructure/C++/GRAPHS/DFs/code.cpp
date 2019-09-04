#include <bits/stdc++.h>
using namespace std;

class Graph

{

  int V;

  list<int> *adj;

public:
  Graph(int V)
  {

    this->V = V;

    adj = new list<int>[V];
  }
  void addEdge(int v, int w)
  {

    adj[v].push_back(w);
  }
  //CALLING FUNCTION FOR DFS
  void DFS(int v)
  {

    /* Parameter V is passed in case of connected graph Traversal*/

    bool *visited = new bool[V];
    memset(visited, 0, sizeof visited);
    /*
    DFS TRAVERSAL FOR CONNECTED GRAPHS.
                    DFSUtil(v, visited);
    */

    /* Either of the two sections Depending on the type of Graphs.*/

    // CHANGES IN CODE TO DO COMPLETE TRAVERSAL OF DISCONNECTED GRAPHS.
    for (int i = 0; i < V; i++)
    {
      if (visited[i] == false)
      {
        DFSUtil(i, visited);
      }
    }
  }
  //DFS TRAVERSAL FUNCTION SINCE IT IS INSPIRED BY RECURSION
  void DFSUtil(int v, bool *visited)
  {

    visited[v] = true;

    cout << v << " ";

    for (auto it : adj[v])
    {
      if (!visited[it])
      {
        DFSUtil(it, visited);
      }
    }
  }
};

int main()

{

  Graph g(4);

  g.addEdge(0, 1);

  g.addEdge(0, 2);

  g.addEdge(1, 2);

  g.addEdge(2, 0);

  g.addEdge(2, 3);

  g.addEdge(3, 3);

  cout << "Following is Depth First Traversal"

          " (starting from vertex 2) \n";

  g.DFS(2);

  return 0;
}