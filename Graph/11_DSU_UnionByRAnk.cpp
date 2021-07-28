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
        return findset(parent[i],parent);
    }
    //DSU Union
    void unionset(int x, int y, int parent[],int rank[]){
        int s1=findset(x,parent);
        int s2=findset(y,parent);
        // if(s1!=s2){
        //     parent[s2]=s1;
        // }
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

    bool contain_cycle(){
        //DSU logic to check if graph is cyclic or not
        int *parent = new int[V];
        int *rank =new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
        for(auto edge: l){
            int i=edge.first;
            int j=edge.second;

            int s1=findset(i,parent);
            int s2= findset(j,parent);
            if(s1!=s2){
                unionset(s1,s2,parent,rank);
            }
            else {
                // cout<<"Same Parents"<<s1<<" and "<<s2<<endl;
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
                cout<<"Rank Array"<<endl;
                for (int i = 0; i < V; i++){
                    cout<<rank[i]<<" ";
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
        cout<<"Rank Array"<<endl;
        for (int i = 0; i < V; i++){
            cout<<rank[i]<<" ";
        }
        cout<<endl;
        
        delete[] parent;
        delete[] rank;
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