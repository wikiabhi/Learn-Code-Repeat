// DFS Traversal
#include <iostream>
#include <queue>
using namespace std;

void printDFS(int** edges, int n, int start, bool* visited){
    cout << start << endl;
    visited[start] = true;

    for(int i=0; i<n; i++){
        if(i == start){
            continue;
        }
        if(edges[start][i] == 1){
            if(visited[i]){
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS(int** edges, int n, int start){
    // Queue for pending Vertices
    queue<int> pendingVertices;

    // Visited array 
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    // Push the starting vertex to the queue and mark it as visited
    pendingVertices.push(start);
    visited[start] = true;


    while(!pendingVertices.empty()){
        // Pop the front vertex in the queue
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();

        // Print current vertex
        cout << currentVertex << endl;

        // Push the adjacent vertices of the current vertex which are not visited yet and mark them visited
        for(int i=0; i<n; i++){
            if(i == currentVertex){
                continue;
            }
            if(edges[currentVertex][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
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

    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    // printDFS(edges, n, 0, visited);

    printBFS(edges, n, 0);
    
    // Delete the memory allocations
    delete[] visited;
    for(int i=0; i<n; i++){
        delete[] edges[i];
    }
    delete[] edges;
}