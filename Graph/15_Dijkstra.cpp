#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>>* l;

    public:        
    Graph(int v){
        V=v;
        // l=new list<int>[V];
    }
    void addEdge(int u, int v,int w, bool undir=true){
        l[u].push_back({w,v});
        if(undir)
            l[v].push_back({w,u});
    }
    
    int dijkstra(int src, int dest){
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> s;

        dist[src] =0;
        s.insert({0,src});

        while(!s.empty()){

            auto it= s.begin();
            int node = it->second;
            int nodesdist= it->first;
            s.erase(it);

            for(auto nbrpair : l[node]){
                int nbr = nbrpair.second;
                int currEdge = nbrpair.first;

                if(nodesdist + currEdge < dist[nbr]){
                    auto f =s.find({dist[nbr],nbr});
                    if(f!=s.end()){
                        s.erase(f);
                    }

                    dist[nbr]= nodesdist + currEdge;
                    s.insert({dist[nbr],nbr});
                }
            }
        }
        for (int i = 0; i < V; i++){
            cout<<"Node i"<< i <<" Dist "<<dist[i]<<endl;
        }
        return dist[dest];
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,5);
    g.addEdge(3,4,5);
    cout<<g.dijkstra(0,4);
return 0;
}