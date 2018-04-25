#include <iostream>
using namespace std;

void merge(int input[], int si , int ei){
  
    int size = ei-si+1;
    int mid = (si+ei)/2;
    
    int i=si;
    int j = mid+1;
    int k =0;
    
    int arr[ei-si];
    
    while(i <= mid && j <= ei){
      if(input[i] <= input[j]){
         arr[k] = input[i];
           i++; 
           k++;
      }else{
         arr[k] = input[j];
           j++; 
           k++;
      }

      
    }
    
    while(i<=mid){
      arr[k] = input[i];
      i++;
      k++;
    }
    
    while(j<=ei){
      arr[k] = input[j];
      j++;
      k++;
    }
    
    for(int i=si,j=0; i<=ei; i++){
      input[i] = arr[j++];
    }

    return;
	 
}


void myMergeSort(int input[], int si, int ei){
  
  if(si >= ei){
    	return;
  }
  
  int mid = (si+ei)/2;
  
  myMergeSort(input, si , mid);
  myMergeSort(input, mid+1, ei);
    
  merge(input, si, ei);
  
}

void mergeSort(int input[], int size){  
  myMergeSort(input, 0, size-1);
}

int main(){
  int n;
  cin >> n;

  int * arr = new int[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  mergeSort(arr, n);

  for(int i=0; i<n; i++){
    cout << arr[i] << " " ;
  }

}