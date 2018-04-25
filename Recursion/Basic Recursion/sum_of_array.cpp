#include <iostream>
using namespace std;

int sum(int input[], int n) {
  	if(n == 1){
      return input[0];
    }
  
  	return input[0] + sum(input+1, n-1);
}


int main(){
	int size;
	cin >> size;

	int * arr = new int[size];
	for(int i=0; i<size; i++){
		cin >> arr[i];
	}

	cout << sum(arr, size);
}



