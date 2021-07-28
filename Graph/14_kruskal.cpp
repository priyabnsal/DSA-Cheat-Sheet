#include<bits/stdc++.h>
using namespace std;

class DSU{
    int *parent;
    int *rank;
    public:
    DSU(int n){
        parent = new int[n];
        rank = new int [n];
        for (int i = 0; i < n; i++)
        {
            parent[i]=-1; 
            rank[i]=1;
        }
        
    }
    int find(int i){
        if(parent[i]==-1)
            return i;
        return parent[i]= find(parent[i]);
    }
    void unionset(int x, int y){
        int s1=find(x);
        int s2=find(y);
        
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+= rank[s1];
            }
            else{
                parent[s2]=s1;
                rank[s1]+= rank[s2];
            }
        }
    }
};

class Graph{
    int V;
    vector<vector<int>> edgelist;
    public:
    Graph(int v){
        this->V=v;
    }
    void addEdge(int x, int y, int w){
        edgelist.push_back({w,x,y});
    }

    int Kruskal(){
        // 1. sort edges
        sort(edgelist.begin(),edgelist.end());

        //init DSU
        DSU s(V);
        int ans=0;
        for(auto edge : edgelist){
            int w= edge[0];
            int x= edge[1];
            int y= edge[2];

            if(s.find(x)!= s.find(y)){
                s.unionset(x,y);
                ans+=w;
            }
        }
        return ans;
    }
};

int main(){
   /* Graph g(6);
    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);

    cout<<g.Kruskal();
*/
 int n,m;
    // cout<<"Enter No of nodes"<<endl;
    cin>>n;
    // cout<<"Enter no of edges"<<endl;
    cin>>m;
    Graph g(n);
    // cout<<"Enter Node x and Y then weight"<<endl;
    for (int i = 0; i < m; i++){
        int x,y,w;
        cin>>x>>y>>w;
        g.addEdge(x-1,y-1,w);
    }
    cout<<g.Kruskal()<<endl;
    return 0;
    
}
// 4 5
// 1 2 10
// 2 3 15
// 1 3 5 
// 4 2 2 
// 4 3 40