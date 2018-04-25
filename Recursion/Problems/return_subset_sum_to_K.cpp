#include <iostream>
using namespace std;

int helper(int *input,int n,int si,int out[][50],int k){
    if(si==n){
      if(k==0){
        out[0][0] = 0;
        return 1;
      }else{
        return 0;
      }
    }
    int small1[1000][50];
    int small2[1000][50];
 
  int size1 = helper(input,n,si+1,small1,k);
  int size2 = helper(input,n,si+1,small2,k-input[si]);
  int row =0;
  for(int i=0;i<size1;i++){
    for(int j=0;j<=small1[i][0];j++){
      out[row][j] = small1[i][j];
    }
    row++;
  }
   for(int i=0;i<size2;i++){
     out[row][0] = small2[i][0]+1;
     out[row][1] = input[si];
    for(int j=1;j<=small2[i][0];j++){
      out[row][j+1] = small2[i][j];
    }
    row++;
  }
  return row;
  
}
int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    return helper(input,n,0,output,k);
}

int main(){
  int n;
  cin >> n;

  int * arr = new int[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  int k;
  cin >> k;

  //enter output
  subsetSumToK(input, n, output, k);


}