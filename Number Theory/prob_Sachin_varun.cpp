#include <iostream>
#include <utility>
using namespace std;


class triplet{
public:
	long long gcd;
	long long x; 
	long long y;
};

triplet gcdExtendedEuclid(long long a, long long b){
	// Base case
	if(b == 0){
		triplet myAns;
		myAns.gcd = a;
		myAns.x = 1;
		myAns.y = 0;

		return myAns;
	}

	triplet smallAns = gcdExtendedEuclid(b, a%b);

	// Extended Euclid says

	triplet myAns;
	myAns.gcd = smallAns.gcd;
	myAns.x = smallAns.y;
	myAns.y = smallAns.x - ((a/b) * smallAns.y);

	// cout << myAns.x << " * " << a << " + " <<myAns.y << " * " << b << " = " << myAns.gcd << endl;
	return myAns;
}


long long  modInverse(long long a, long long m){
	long long x = gcdExtendedEuclid(a,m).x;

	return (x % m + m) % m;
}

long long solveSachin(long long a, long long b, long long d){
	int smallestY;

	smallestY = ((d % a) * (modInverse(b,a) % a)) % a;

	float first = float(d)/float(b);
	float second = float(first - smallestY)/float(a);
	int n = second; 

	return n+1; 
}

int main(){
	int t;
	cin >> t;

	long long * result = new int[t];

	for(int i=0; i<t; i++){
		long long a, b, d;

		cin >> a >> b >> d;
		result[t] = solveSachin(a,b,d);
	}

	for(int i=0; i<t; i++){
		cout << result[t] << endl;
	}


	smallestY = ((d % a) * (modInverse(b,a) % a)) % a;
}

