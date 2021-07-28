#include<bits/stdc++.h>>
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
    void printlist(){
        for(int i=0;i<V;i++)
        {
            std::cout<<i<<" --> ";
            for(auto node:l[i])
               std::cout<<node<<", ";
        std::cout<<endl;
        }
        
    }
};

int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.printlist();
return 0;
}