#include <iostream>
using namespace std;

bool isValid(int maze[][20], int n, int i, int j, int output[][20]){
  
  if(i>=0 && i<n && j>=0 && j<n){
    if(maze[i][j] == 1 && output[i][j] == 0){
      return true;
    }
  }
  return false;
}
void solver(int maze[][20], int n, int i, int j, int output[][20]){
	
  	if(i == n-1 && j == n-1){
      output[i][j] = 1;
      //print a solution 
      cout << "............." << endl;

      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          cout << output[i][j] << " ";
        }
        cout << endl;        
      }
      cout << "............." << endl << endl;
      
      return;
    }
  	
  
    if(isValid(maze,n, i, j, output)){
      output[i][j] = 1;
      
      
      solver(maze, n, i-1, j, output);
      solver(maze, n, i+1, j, output);
      solver(maze, n, i, j-1, output);
      solver(maze, n, i, j+1, output);
      
      output[i][j] = 0;
      
      return;
    }
  	return;     
}


void ratInAMaze(int maze[][20], int n){
  int output[100][20] = {0};
  solver(maze, n, 0,0, output);
}


int main(){
	int n;
	cin >> n;

	int input[n][20];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> input[i][j];	
		}
	}

	ratInAMaze(input, n);

}