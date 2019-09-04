#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> *adj,int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> *v,int N)
{
    for(int i=0;i<N;i++)
    {
        cout<<"For Node"<<i<<endl;
        for(auto it:v[i])
        {
            cout<<"------->"<<it;
        }
        cout<<endl;
    }
}

int main()
{
    vector<int> adj[5]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    printGraph(adj, 5);
    return 0; 
}