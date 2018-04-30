#include <iostream>
#include<cstring>
using namespace std;
int output[11][11];

bool isValid(int n, int i, int j){
	//horizantal row check
	for(int q =0; q<n; q++){
		if(output[i][q] == 1){
			return false;
		}
	}
	//vertial column check
	for(int p =0; p<n; p++){
		if(output[p][j] == 1){
			return false;
		}
	}
	//diagonals check
	// right up
	for(int p=i, q=j; p>=0 && q<n; p--, q++ ){
		if(output[p][q] == 1){
			return false;
		}
	}
	//right down
	for(int p=i, q=j; p<n && q<n; p++, q++ ){
		if(output[p][q] == 1){
			return false;
		}
	}
	//left up
	for(int p=i, q=j; p>=0 && q>=0; p--, q-- ){
		if(output[p][q] == 1){
			return false;
		}
	}
	//left down 
	for(int p=i, q=j; p<n && q>=0; p++, q-- ){
		if(output[p][q] == 1){
			return false;
		}
	}

	return true;
}

void solver( int n, int i){

	if(i == n){
		for(int i=0; i<n; i++){
 			for(int j=0; j<n; j++){
 			 cout << output[i][j] << " ";
 			}
 			cout << endl;
 		}
      	cout << ".................." <<endl;
		return ;
	}

	for(int j=0; j<n; j++){
			if(isValid(n,i,j)){
				output[i][j] = 1;
				solver(n, i+1);
				output[i][j] = 0;
			}
	}
	return;
}

void placeNQueens(int n){

	memset(output, 0, 11*11*sizeof(int));
  	solver(n, 0);

}

int main(){
	int n;
	cin >> n;

	placeNQueens(n);
}
