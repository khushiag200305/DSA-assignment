#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void BFS(vector<int>adj[],int v,int s)
{
    bool vis[v+1];
    for(int i=0;i<v;i++)
    vis[i]=false;
    queue<int>q;
    vis[s]=true;
    q.push(s);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:adj[u])
        {
            if(vis[v]==false)
            {
                vis[v]=true;
                q.push(v);
            }
        }
    }
}
int main()
{
    int v = 6;
    vector<int> adj[v];
    adj[0].push_back(3);
    adj[0].push_back(4);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(1);
    adj[4].push_back(2);
    adj[4].push_back(5);
     adj[5].push_back(4);

    

    BFS(adj, v, 0);
}
