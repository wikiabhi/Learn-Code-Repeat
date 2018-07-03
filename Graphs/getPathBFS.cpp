#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

void getPathBFS(int ** edges, int n, bool * visited, int start, int end){
    map <int,int> pathMap;
    queue<int> pendingVertices;
    // vector<int> path;

    pendingVertices.push(start);
    visited[start] = true;

    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();

        for(int i=0; i<n; i++){
            if(i == currentVertex){
                continue;
            }
            if(edges[currentVertex][i] == 1 && !visited[i]){
                if(i == end){
                    // create the path from map
                    cout << end << " ";
                    int previousVertex = pathMap[end];
                    while(previousVertex != start){
                        cout << previousVertex << " ";
                        previousVertex = pathMap[previousVertex];
                    }
                    cout << start;
                    return; 
                }

                pendingVertices.push(i);
                pathMap.insert(make_pair(i, currentVertex));
                visited[i] = true;
            }
        }
    }

    
    return;
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
    
  
    getPathBFS(edges, n, visited, start, end);

    // if(!path.empty()){
    //     for(int i=0; i<path.size(); i++){
    //        cout << path[i] << " ";
    //     }
    // }

    // Delete the memory allocations
    for(int i=0; i<n; i++){
        delete[] edges[i];
    }
    delete[] edges;
}