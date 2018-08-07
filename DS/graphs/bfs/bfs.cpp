#include <bits/stdc++.h>
using namespace std;
class Graphs {
  int V;
  // Array Of linked List.
  list<int> *adjList;

public:
  Graphs(int v) {
    V = v;
    adjList = new list<int>[V];
  }
  void addEdge(int u, int v, bool bidir = true) {
    adjList[u].push_back(v);
    if (bidir) {
      adjList[v].push_back(u);
    }
  }
  void printAdjList() {
    for (int i = 0; i < V; i++) {
      cout << i << "->";
      for (int node : adjList[i]) {
        cout << node << ",";
      }
      cout << endl;
    }
  }

  void bfs(int src, int dest) {
    queue<int> q;
    bool *visitedArray = new bool[V + 1]{false};
    int *distance = new int[V + 1]{0};
    int *parent = new int[V + 1];
    memset(parent, -1, sizeof(parent));

    // cout << src << " --> ";
    q.push(src);
    visitedArray[src] = true;

    while (!q.empty()) {
      int node = q.front();
      cout << node << "-->";
      q.pop();

      for (int neighbour : adjList[node]) {
        if (!visitedArray[neighbour]) {
          q.push(neighbour);
          visitedArray[neighbour] = true;

          distance[neighbour] = distance[node] + 1;
          parent[neighbour] = node;
        }
      }
    }
    cout << endl;

    for (int i = 0; i < V; i++) {
      cout << "Distance of " << i << " Node " << distance[i] << endl;
    }

    cout << "Shortest Path is\n";
    int temp = dest;
    while (temp != 1) {
      cout << temp << "<--";
      temp = parent[temp];
    }
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  Graphs g(7);

  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(0, 4);
  g.addEdge(2, 4);
  g.addEdge(3, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 5);
  g.addEdge(3, 4);

  // g.printAdjList();
  g.bfs(0, 5);
}

// for (int i = 0; i < 4; i++) {
//   int a, b;
//   cin >> a >> b;
//   g.addEdge(a, b);
// }

// int t;
// cin >> t;
// while (t--) {
//   int m, n;
//   cin >> m >> n;
//   Graphs g(m);
//   while (n--) {
//     int a = 0, b = 0;
//     cin >> a >> b;
//     g.addEdge(a, b);
//   }
//   g.printAdjList();
// }
