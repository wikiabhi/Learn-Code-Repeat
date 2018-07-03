
#include <iostream>
#include <vector>
using namespace std;

vector<int> getPathDFS(int ** edges, int n, bool * visited, int start, int end){
    vector<int> path;

    visited[start] = true;
    
    if(start == end){
        path.push_back(end);
        return path;
    }

    for(int i=0; i<n; i++){
        if(edges[start][i] == 1 && !visited[i]){
            path = getPathDFS(edges, n, visited, i, end);
            if(!path.empty()){
                path.push_back(start);
                return path;
            }
        }
    }
    return path;
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

    int start, end;
    cin >> start >> end;

    bool * visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    } 
    
    vector<int> path = getPathDFS(edges, n, visited, start, end);

    if(!path.empty()){
        for(int i=0; i<path.size(); i++){
           cout << path[i] << " ";
        }
    }
    

    // Delete the memory allocations
    for(int i=0; i<n; i++){
        delete[] edges[i];
    }
    delete[] edges;
}