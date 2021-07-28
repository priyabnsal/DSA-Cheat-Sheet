// Not Working.........

// #include<iostream>
// #include<queue>
// using namespace std;



// bool dfshelper(vector<int> graph[], int node, int * visited, int parent, int color){
//     visited[node]=color; //can be 1 or 2
//     for(auto nbr : graph[node]){
//         if(visited[nbr]==0){
//             int subprob = dfshelper(graph,nbr,visited,node,3-color);
//             if(subprob==false)
//                 return false;
//             else if(nbr!=parent and color == visited[node])
//                 return false;
//         }
//     }
//     return true;
// }

// bool dfs(vector<int> graph[], int n){
//     int visited[n]={0}; //0->not visites | 1->Visited color 1 | 2-> visited color 2
//     int color=1;
//     int ans = dfshelper(graph, 0, visited, -1, color);
    
//     return ans;
// }

// int main() {


//     // int V,E;
//     // cout<<"Enter V and E ";
//     // cin>>V>>E;
//     // vector<int> graph[V];
//     // while(E--){
//     //     int x,y;
//     //     cout<<"Enter X to y";
//     //     cin>>x>>y;
//     //     graph[x].push_back(y);
//     //     graph[y].push_back(x);
//     // }
//     int V, E;
//     V = 4 , E = 8;
//       //adjacency list for storing graph
//     vector<int> adj[V];
//       adj[0] = {1,2};
//       adj[1] = {2,3};
//       adj[2] = {1,4};
//       adj[3] = {3,4};
//     if(dfs(adj,V)){
//         cout<<"yes bipartite";
//     }
//     else
//     cout<<"Not Bipartite";

//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;

bool dfs_helper(vector<int> graph[],int node,int *visited,int parent, int color){
	//come to node
	visited[node] = color; //1 or 2, both mean visited

	for(auto nbr : graph[node]){

		if(visited[nbr]==0){
			int subprob = dfs_helper(graph,nbr,visited,node,3-color);
			
			if(subprob==false){
				return false;
			}

		}
		else if(nbr!=parent and color==visited[nbr]){
			return false;
		}

	}
	return true;
}


bool dfs(vector<int> graph[],int N){

	int visited[N] = {0};  // 0- Not Visited, 1 - Visited Color is 1, 2 - Visted Color 2

	int color = 1;
	int ans = dfs_helper(graph,0,visited,-1,color);
	//later one

	//colors
	for(int i=0;i<N;i++){
		cout<<i<<" - Color "<<visited[i] <<endl;
	}

	//
	return ans;
}


int main(){
	int N,M;

	cin>>N>>M;

	vector<int> graph[N];
	while(M--){
		int x,y;
		cin>>x>>y;

		graph[x].push_back(y);
		graph[y].push_back(x);

	}

	//BFS or DFS, by coloring the nodes at each step (current node has color 1, nbr should have a color 2)
	if(dfs(graph,N)){
		cout<<"Yes its bipartite";
	}
	else{
		cout<<"Not bipartite";
	}



	return 0;
}