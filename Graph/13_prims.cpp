#include<bits/stdc++.h>
using namespace std;


class Graph{
    int V;
    vector<pair<int,int>>* l;
    public:
        
    Graph(int n){
        V=n;
        l=new vector<pair<int,int>>[n];
    }
    void addEdge(int x,int y, int w){
        l[x].push_back({y,w});
        l[y].push_back({x,w});

    }
    int prims_mst(){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > Q;

        bool *visited= new bool[V]{0};
        int ans=0;
        //begin
        Q.push({0,0}); //weight, node
        while (!Q.empty()){
            //pick out theedgewith min weight
            auto best = Q.top();
            Q.pop();

            int to = best.second;
            int weight = best.first;

            if(visited[to]){
                //discard edge and continue
                continue;
            }
            ans += weight;
            visited[to]=1;

            for(auto x: l[to]){
                if(visited[x.first]==0){
                    Q.push({x.second, x.first});
                }
            }
        }
        return ans;
    }
     
};

int main() {
    // N - the number of nodes and M - the number of edges
    int n,m;
    cout<<"Enter No of nodes"<<endl;
    cin>>n;
    cout<<"Enter no of edges"<<endl;
    cin>>m;
    Graph g(n);
    cout<<"Enter Node x and Y then weight"<<endl;
    for (int i = 0; i < m; i++){
        int x,y,w;
        cin>>x>>y>>w;
        g.addEdge(x-1,y-1,w);
    }
    cout<<g.prims_mst()<<endl;
    
return 0;
}
// Input:
// 4 5
// 1 2 10
// 2 3 15
// 1 3 5
// 4 2 2
// 4 3 40