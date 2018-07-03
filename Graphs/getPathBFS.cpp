/**
 * Created on: Tue, Jul 3, 2018 9:22 PM

 * @author: wikiabhi (Abhishek)
*/

/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), 
find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
*/

#include <iostream>
#include <map>
#include <queue>

using namespace std;

void getPathBFS(int ** edges, int n, bool * visited, int start, int end){
    map <int,int> pathMap;
    queue<int> pendingVertices;

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
                pendingVertices.push(i);
                pathMap.insert(make_pair(i, currentVertex));
                visited[i] = true;

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