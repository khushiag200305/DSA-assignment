#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> adj[1000];

void dijkstra(int src, int V){
    vector<int> dist(V, 1e9);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src}); // distance, node

    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        int d = p.first;
        int node = p.second;

        for(auto nbr : adj[node]){
            int nxt = nbr.first;
            int w = nbr.second;

            if(dist[nxt] > d + w){
                dist[nxt] = d + w;
                pq.push({dist[nxt], nxt});
            }
        }
    }

    cout << "Distances from node " << src << ":\n";
    for(int i=0;i<V;i++)
        cout << "To " << i << " = " << dist[i] << endl;
}

int main(){
    int V = 5;

    adj[0] = {{1,2},{2,4}};
    adj[1] = {{2,1},{3,7}};
    adj[2] = {{4,3}};
    adj[3] = {{4,1}};
    adj[4] = {};

    dijkstra(0, V);
}
