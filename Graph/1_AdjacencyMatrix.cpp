#include<iostream>
using namespace std;

int vertArr[20][20]; //the adjacency matrix initially 0
int count = 0;

void displayMatrix(int v) {
   int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
         cout << vertArr[i][j] << " ";
      }
      cout << endl;
   }
}

void add_edge(int u, int v) {       //function to add edge into the matrix
   vertArr[u][v] = 1;
   vertArr[v][u] = 1;
}
main(int argc, char* argv[]) {
   int v = 6;    //there are 6 vertices in the graph
   add_edge(0, 4);
   add_edge(0, 3);
   add_edge(1, 2);
   add_edge(1, 4);
   add_edge(1, 5);
   add_edge(2, 3);
   add_edge(2, 5);
   add_edge(5, 3);
   add_edge(5, 4);
   displayMatrix(v);
}
//     int n,m;
//     cout<<"Enter The No of Nodes";
//     cin>>n;
//     cout<<"Enter the no of Edges";
//     cin>>m;

//     int adj[n+1][n+1];

//     for (int i = 0; i < m; i++)
//     {
//         int u,v;
//         cout<<"Enter u";
//         cin>>u;
//         cout<<"Enter v";
//         cin>>v;
//         adj[u][v]=1;
//         adj[v][u]=1;
//     }
//     for (int i = 0; i < m; i++)
//     {
        
//     }
    
//     return 0;
// }