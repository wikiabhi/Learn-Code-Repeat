#include <iostream>
#include <climits>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(1)

void insertionSort(int n, int* arr){
    // Initially, let value at 0th index is sorted and right to it is unsorted
    for(int i=1; i<n; i++){
        // create a dummy hole at ith position
        int value = arr[i];
        int hole = i;

        while(hole>0 && arr[hole - 1] > value){
            // swap hole to one position left
            arr[hole] = arr[hole-1];
            hole--;
        }

        // Insert value at its correct position 
        arr[hole] = value;
    }
}


int main(){
    int n;
    cin >> n;

    int * arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    insertionSort(n, arr);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}