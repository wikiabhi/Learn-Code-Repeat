/**
 * Created on: Tue, Jul 3, 2018 7:19 PM

 * @author: wikiabhi (Abhishek)
*/

/*
    Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), 
    check if there exists any path between them or not. Print true or false.
    V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
    E is the number of edges present in graph G.
*/

#include <iostream>
using namespace std;

bool hasPath(int ** edges, int n, int start, int end, bool * visited){
    if(edges[start][end] == 1){
        return true;
    }

    visited[start] = true;

    for(int i=0; i<n; i++){
        if(edges[start][i] == 1 && !visited[i]){
            if(hasPath(edges, n, i, end, visited)){
                return true;
            }
        }
    }

    return false;
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

    bool result =  hasPath(edges, n, start, end, visited);
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