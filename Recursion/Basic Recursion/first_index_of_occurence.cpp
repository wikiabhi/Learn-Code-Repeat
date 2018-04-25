#include <iostream>
using namespace std;

int firstIndex(int input[], int size, int x) {
  if( size == 1 && input[0] != x){
    return -1;
  }
  
  if(input[0] == x){
    return 0;
  }
  
  int index = firstIndex(input+1, size-1 , x);
  
  if(index != -1){
    return 1 + index;
  }else{
    return -1;
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

  cout << firstIndex(arr, size, x);

}