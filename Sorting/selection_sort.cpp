#include <iostream>
#include <climits>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(1)

void selectionSort(int n, int * arr){
    for(int i=0; i<n-1; i++){
        // Select the smallest from (i+1)th index to (n-1)th index
        int minIndex = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        // Swap the minIndex element with that of ith index
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
} 

int main(){
    int n;
    cin >> n;

    int * arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    selectionSort(n, arr);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}