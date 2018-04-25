#include <iostream>
#include <utility>
using namespace std;


class triplet{
public:
	int gcd;
	int x; 
	int y;
};

triplet gcdExtendedEuclid(int a, int b){
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


void modInverse(int a, int m){
	triplet ans = gcdExtendedEuclid(a,m);
	cout << "Multiplicative modulo inverse is : " << ans.x << endl;
}

int main(){
	int a = 5;
	int m = 17;

	modInverse(a,m);
}

