#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for(int nbr : adj[node]) {
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    cout << "BFS Traversal: ";
    g.BFS(0);
}
