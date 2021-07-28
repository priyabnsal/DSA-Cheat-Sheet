#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* l;
    public:
        
    Graph(int v){
        V=v;
        l=new list<int>[V];
    }
    void addEdge(int i, int j, bool undir=true){
        l[i].push_back(j);
        if(undir)
            l[j].push_back(i);
    }
    
    void bfs(int source){
        queue<int> q;
        bool *visited = new bool[V]{0};
        q.push(source);
        visited[source]=true;
        
        while(!q.empty()){
            int f=q.front();
            cout<<f<<" ";
            q.pop();
             for(auto nbr:l[f]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr]=true;
            }
        }
        }  
    }
    void bfs_toposort(){
        vector<int> indegree(V,0);
        for (int i = 0; i < V; i++)
        {
            for(auto nbr:l[i])
                indegree[nbr]++;
        }
        //bfs
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while (!q.empty()){
            int node=q.front();
            cout<<node<<" ";
            q.pop();
            for(auto nbr: l[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }
    }
    void dfs(int node,vector<bool>&visited, list<int>& order){
        visited[node]=true;
        for (int nbr: l[node])
        {
            if(!visited[nbr])
                dfs(nbr,visited,order);
        }
        order.push_front(node);
        return;
        
    }
    void dfs_topo(){
        vector<bool> visited(V,false);
        list<int> ordering;

        for(int i=0;i<V;i++){
            if(!visited[i])
            {
                dfs(i,visited,ordering);
            }
        }
        for(auto nbs:ordering)
        cout<< nbs<<" ";
        cout<<endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0,2,false);
    g.addEdge(1,2,false);
    g.addEdge(1,4,false);
    g.addEdge(2,3,false);
    g.addEdge(3,5,false);
    g.addEdge(4,5,false);
    
    
    // g.addEdge(1,2);
    // g.addEdge(4,5);
    // g.bfs(1);
    g.bfs_toposort(); //not working
    // g.dfs_topo();
return 0;
}