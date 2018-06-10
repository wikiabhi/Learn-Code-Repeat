#include <iostream>
#include <cmath>
using namespace std;

double areaPolygon(int n, int* x, int* y){
	double area = 0;

	for(int i=1; i<n-1; i++){
		int x1 = x[i] - x[0];
		int y1 = y[i] - y[0];

		int x2 = x[i+1] - x[0];
		int y2 = y[i+1] - y[0];

		int cross_product = x1*y2 - y1*x2;

		area += cross_product;
	}
	
	return abs(area/2);
}

int main(){
	int n;
	cin >> n;

	int* x = new int[n];
	int* y = new int[n];

	for(int i=0; i<n; i++){
		cin >> x[i]; 
	}
	for(int i=0; i<n; i++){
		cin >> y[i]; 
	}		

	cout << areaPolygon(n, x, y);
}