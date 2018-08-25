#include <iostream>
#include <climits>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(1)


void bubbleSort(int n, int* arr){
    for(int i=0; i<n-1; i++){
        // Bubble up the largest element
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                // swap them
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;

    int * arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    bubbleSort(n, arr);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}