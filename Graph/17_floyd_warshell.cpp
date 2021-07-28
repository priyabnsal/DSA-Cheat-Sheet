// C++ Program for Floyd Warshall Algorithm
#include <bits/stdc++.h>
using namespace std;

#define INF 10000

vector<vector<int> > floydWarshall(vector<vector<int>> graph)
{
    int V=graph.size();
	vector<vector<int>> dist(graph);

    for(int k=0;k<V;k++){
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
        		if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
            }		
        }
    }
	return dist;
}

int main()
{
    // INF => INT_MAX  
	vector<vector<int>> graph = { 
                            { 0, INF, -2, INF },
						    { 4, 0, 3, INF },
						    { INF, INF, 0, 2 },
						    { INF, -1, INF, 0 } };

	// Print the solution
	auto result = floydWarshall(graph);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result.size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
	return 0;
}

// O/p:
// 0 -1 -2 0 
// 4  0  2 4
// 5  1  0 2
// 3 -1  1 0