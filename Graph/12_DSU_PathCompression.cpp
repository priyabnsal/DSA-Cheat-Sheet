#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>> l;
public:
    Graph(int v){
        this->V=v;
    }
    int addEdge(int u,int v){
        l.push_back(make_pair(u,v));
    }
    //DSU Find
    int findset(int i, int parent[]){
        if(parent[i]==-1)
            return i;
        return parent[i]=findset(parent[i],parent);
    }
    //DSU Union
    void unionset(int x, int y, int parent[]){
        int s1=findset(x,parent);
        int s2=findset(y,parent);
        if(s1!=s2){
            parent[s2]=s1;
        }
    }

    bool contain_cycle(){
        //DSU logic to check if graph is cyclic or not
        int *parent = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i]=-1;
        }
        for(auto edge: l){
            int i=edge.first;
            int j=edge.second;

            int s1=findset(i,parent);
            int s2= findset(j,parent);
            if(s1!=s2){
                unionset(s1,s2,parent);
            }
            else {
                cout<<"Index array"<<endl;
                for (int i = 0; i < V; i++){
                    cout<<i<<" ";
                }
                cout<<endl;
                cout<<"Parent array "<<endl;
                for (int i = 0; i < V; i++){
                    cout<<parent[i]<<" ";
                }
                cout<<endl;
                return true;
            }
                
        }
        
        cout<<"Parent array "<<endl;
        for (int i = 0; i < V; i++){
            cout<<parent[i]<<" ";
        }
        cout<<endl;
        delete[] parent;
        return false;
    }
};

int main(){

    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,4);
    g.addEdge(5,6);
    g.addEdge(2,5);
    g.addEdge(2,6);
    cout<<g.contain_cycle()<<endl;
    return 0;
}