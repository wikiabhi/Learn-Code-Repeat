#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
	for(int i=2; i*i <= n; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

long long calculatePower(int n, int i){
	long long power = 0;
	long long val = 1;

	for(int j = i; val!=0; j *= i){
		val = n/j;
		power += val;
	}

	return power;

}

long long countDivisor(int n){
	// Return number of divisors in n!

	long long divisors = 1;

// Since the answer can be very large, print answer modulo 10^9+7 
	long long z = pow(10,9) + 7;


	for(int i=2; i<=n; i++){
		if(isPrime(i)){
			long long pow = calculatePower(n, i);
			divisors *= ((pow + 1) % z);
		}
	}

	long long ans = divisors % z;

	return ans ;

}
int main(){
	int t;
	cin >> t;

	int* arr = new int[t];

	for(int i=0; i<t; i++){
		cin >> arr[i];
	}	


	for(int i=0; i<t; i++){
		cout << countDivisor(arr[i]) << endl;
	}
}