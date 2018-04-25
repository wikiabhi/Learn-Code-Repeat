#include <iostream>
using namespace std;


bool checkNumber(int input[], int size, int x) {

  if(size == 1 && input[0] != x){
    return false;
  }
  
  if(input[0] == x){
    	return true;
  }
  return checkNumber(input+1, size-1, x);

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

  cout << checkNumber(arr, size, x);

}
