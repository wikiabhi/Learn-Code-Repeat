#include <iostream>
using namespace std;

// input - input array
// size - length of input array
// element - value to be searched

int binarySearchHelper(int input[], int si, int ei, int element){
  	if(si > ei){
      return -1;
    }
  	int mid = (si+ei)/2;
  
  	if(input[mid] == element){
      return mid;
    }else if(input[mid] < element){
      return binarySearchHelper(input, mid+1, ei, element);
    }else{
      return binarySearchHelper(input, si, mid-1, element);
    }  
}

int binarySearch(int input[], int size, int element) {
   return binarySearchHelper(input, 0, size-1, element);
}

int main(){
	int size;
	cin >> size;

	int * input = new int[size];
	for(int i=0; i<size; i++){
		cin >>input[i];
	}

	int element;
	cin >> element;

	cout << binarySearch(input, size, element); 
}