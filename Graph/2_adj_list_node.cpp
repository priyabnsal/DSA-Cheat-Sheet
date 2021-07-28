#include<bits/stdc++.h>>
using namespace std;

class Node{
  public:
    string name;
    list<string> nbrs;
    Node(string name){
        this->name=name;
    }
};
class Graph{
    
    unordered_map<string,Node*> m;
    public:
    Graph(vector<string>cities){
            for(auto city:cities)
                m[city]=new Node(city);
    }
    void addEdge(string i, string j, bool undir=false){
        m[i]->nbrs.push_back(j);
        if(undir)
            m[j]->nbrs.push_back(i);
    }
    void printlist(){
     
            for(auto citypair: m){
                auto city= citypair.first;
                Node* node=citypair.second;
                std::cout<<city<<" --> ";
                for(auto nbrs:node->nbrs)
                    std::cout<<nbrs<<", ";
            cout<<endl;
            }
    }
};

int main() {
    vector<string> city={"delhi","pnp","noida","piet"};
    Graph g(city);
    g.addEdge("delhi","pnp");
    g.addEdge("pnp","noida");
    g.addEdge("delhi","noida");
    g.addEdge("noida","piet");
    g.printlist();
return 0;
}