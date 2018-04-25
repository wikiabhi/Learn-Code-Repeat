#include <iostream>
using namespace std;

void swap(int* a, int* b){
  int c = *a;
  *a = *b;
  *b = c;
}


int partition(int input[], int si, int ei){
  	
  	int smaller = 0;
  	for(int i=si+1; i<=ei; i++){
      if(input[i] <= input[si]){
        smaller ++;
      }
    }
  
  	int index = si+smaller;
  
  	swap(&input[si], &input[index]);
  	
  	int i=si;
  	int j=ei;
  	
  	while(i < index && j > index){
      if(input[i] <= input[index]){
        i++;
        continue;
      }
      
      if(input[j] > input[index]){
        j--;
        continue;
      }
      
      swap(&input[i], &input[j]);
      i++;
      j--;      
    }
  
  
  
  	return index;
  
  
}


void qSort(int input[], int si, int ei){
	if(si >= ei){
      return;
    }  
  
  	int index = partition(input, si, ei);
  
  	qSort(input, si, index-1 );
  	qSort(input, index+1, ei);
  
}


void quickSort(int input[], int size) {
  qSort(input, 0, size-1);
}

int main(){
  int n;
  cin >> n;

  int * arr = new int[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  quickSort(arr, n);

  for(int i=0; i<n; i++){
    cout << arr[i] << " " ;
  }

}