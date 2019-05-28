from collections import defaultdict


class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def DFS(self, v, visited):
        visited[v] = True
        print(v,end=" ")
        for x in self.graph[v]:
            if(visited[x] == False):
                self.DFS(x, visited)

    def FillOrder(self, v, visited, stack):
        visited[v] = True
        for x in self.graph[v]:
            if(visited[x] == False):
                self.FillOrder(x,visited,stack)
        stack = stack.append(v)

    def getTranspose(self):
        g = Graph(self.V)
        for x in self.graph:
            for y in self.graph[x]:
                g.addEdge(y, x)
        return g

    def printStronglyConnected(self):
        stack = []
        visited = [False]*(self.V)
        for i in range(self.V):
            if(visited[i] == False):
                self.FillOrder(i, visited, stack)
        gr = self.getTranspose()
        visited = [False]*(self.V)
        while(stack):
            i = stack.pop()
            if(visited[i] == False):
                gr.DFS(i, visited)
            print()


g = Graph(5)

g.addEdge(1, 0)

g.addEdge(0, 2)

g.addEdge(2, 1)

g.addEdge(0, 3)

g.addEdge(3, 4)

print ("Following are strongly connected components " "in given graph")

g.printStronglyConnected()
