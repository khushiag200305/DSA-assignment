#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V){
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFSUtil(int node, vector<bool>& visited){
        visited[node] = true;
        cout << node << " ";

        for(int nbr : adj[node]){
            if(!visited[nbr])
                DFSUtil(nbr, visited);
        }
    }

    void DFS(int start){
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    cout << "DFS Traversal: ";
    g.DFS(0);
}
