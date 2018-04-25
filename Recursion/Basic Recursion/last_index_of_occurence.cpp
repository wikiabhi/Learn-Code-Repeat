#include <iostream>
using namespace std;

int lastIndex(int input[], int size, int x) {  
	  if( size == 1 && input[0] != x){
	    return -1;
	  }
	 
	  int index = lastIndex(input+1, size-1 , x);
	  
	  if(index == -1){
	    if(input[0] == x){
	      return 0;
	    }else{
	      return -1;
	    }
	  }else{
	    return 1 + index;
	  }
	  
}


int main(){
	  int size;
	  cin >> size;

	  int * arr = new int[size];
	  for(int i=0; i<size; i++){
	    cin >> arr[i];
	  }

	  int x;
	  cin >> x;

	  cout << lastIndex(arr, size, x);
}