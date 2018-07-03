#include <iostream>
using namespace std;

void dfsTraversal(int ** edges, int n, int start, bool * visited){
    visited[start] = true;

    for(int i=0; i<n; i++){
        if(i == start){
            continue;
        }
        if(edges[start][i] == 1 && !visited[i]){
            
            dfsTraversal(edges, n, i, visited);
        }
    } 
}

bool isConnected(int ** edges, int n, bool * visited){
   dfsTraversal(edges, n, 0, visited);

   for(int i=0; i<n; i++){
       if(!visited[i]){
           return false;
       }
   }

   return true;
} 

int main(){
    
    int n; // Number of vertices
    int e; // Number of edges

    cin >> n >> e;

    // Adjacency matrix 
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0; i<e; i++){
        // Take input for first and second vertex of each edge
        int f, s;
        cin >> f >> s;

        // Update the edge in the adjacency matrix
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool * visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    } 

    bool result =  isConnected(edges, n, visited);

    if(result){
        cout << "true";
    }else{
        cout << "false";
    }

    // Delete the memory allocations
    for(int i=0; i<n; i++){
        delete[] edges[i];
    }
    delete[] edges; 

}