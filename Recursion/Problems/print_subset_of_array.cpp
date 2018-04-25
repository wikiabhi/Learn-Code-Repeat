#include <iostream>
using namespace std;

void Helper(int input[],int si,int size,int* out,int osize){
  if(si==size){
    for(int i=0;i<osize;i++){
        cout<<out[i]<<' ';
    }
    cout<<endl;
    return;
  }
  out[osize] = input[si];
  Helper(input,si+1,size,out,osize+1);
  Helper(input,si+1,size,out,osize);
  
  
}
void printSubsetsOfArray(int input[], int size) {
    
  int output[100];
  Helper(input,0,size,output,0);
}

int main(){
	int size;
	cin >> size;

	int * input = new int[size];
	for(int i=0; i<size; i++){
		cin >>input[i];
	}
	
	printSubsetsOfArray(input, size);
}