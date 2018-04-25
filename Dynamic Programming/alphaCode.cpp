#include <iostream>
using namespace std;

int count(int* n, int size, int * arr ){
	if(size == 0){
		return 1;
	}
	if(size == 1){
		return 1;
	}

	if(arr[size] > 0 ){
		return arr[size];
	}

	int output = count(n, size-1, arr);

	if(n[size-2] * 10 + n[size-1] <= 26){
		output += count(n, size-2, arr);		
	}
	arr[size] = output;
	return output;
}
int main(){
	int size;
	cin >> size;

	int* n  = new int[size];
	for(int i=0; i<size; i++){
		cin >> n[i];
	}

	int* arr = new int[size+1];
	for(int i=0; i<size+1 ; i++){
		arr[i] = 0;
	}

	cout << count(n, size, arr);

}