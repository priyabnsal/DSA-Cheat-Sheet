#include<bits/stdc++.h>
using namespace std;

vector<int> bellman_ford (int V, int src, vector<vector<int>> edges){
    vector<int> dist(V+1, INT_MAX);
    dist[src]=0;

    for (int i = 0; i < V-1; i++){
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u] != INT_MAX && dist[u] + w< dist[v]){
                dist[v] = dist[u]+ w;
            }

        }
    }
    //negative wt cycle
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u] != INT_MAX && dist[u] + w< dist[v]){
                cout<<"Negative Node found";
                exit(0);
            }
        }
        return dist;
}

int main(){
    int n,m;
    cout<<"Enter no of nodes and edges ";
    cin>>n,m;
    vector<vector<int>> edges;

    cout<<"Enter u,v and w ";
    for (int i = 0; i < m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    //bellman algo
    vector<int> distance = bellman_ford(n,1,edges);
    for (int i = 1; i <=n ; i++)
    {
        cout<<"Node "<<i<<" is at dist "<<distance[i]<<endl;
    }
    

return 0;
}