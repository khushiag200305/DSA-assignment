#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// ---------- DSU for Kruskal ----------
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if(rank[a] == rank[b]) rank[a]++;
        }
    }
};

// ---------- KRUSKAL ----------
struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

// ---------- PRIM ----------
vector<pair<int,int>> adj[1000]; // node, weight

void prim(int V){
    vector<bool> inMST(V, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 0}); // weight, node

    cout << "Prim MST edges:\n";

    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        int w = p.first, node = p.second;

        if(inMST[node]) continue;
        inMST[node] = true;

        cout << "Picked Node " << node << " with weight " << w << endl;

        for(auto nbr : adj[node]){
            if(!inMST[nbr.first]){
                pq.push({nbr.second, nbr.first});
            }
        }
    }
}

int main(){
    int V = 4;
    vector<Edge> edges = {
        {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}
    };

    // ------------ KRUSKAL MST -------------
    sort(edges.begin(), edges.end(), cmp);
    DSU dsu(V);

    cout << "Kruskal MST edges:\n";
    for(auto e : edges){
        if(dsu.find(e.u) != dsu.find(e.v)){
            cout << e.u << " - " << e.v << " (w=" << e.w << ")\n";
            dsu.unite(e.u, e.v);
        }
    }

    // ------------ PRIM MST -------------
    adj[0].push_back({1,10});
    adj[0].push_back({2,6});
    adj[0].push_back({3,5});
    adj[1].push_back({3,15});
    adj[2].push_back({3,4});

    cout << "\nPrim MST:\n";
    prim(V);
}
