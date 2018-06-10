#include <iostream>
#include <cmath>
using namespace std;

class Point{
	public:
		double x,y;
};

class Polygon{
	public:
		Point* points;
		Polygon(int nPoints){
			points = new Point[nPoints];
		}
};

double areaPolygon(Polygon p, int n){
	double area = 0;

	for(int i=1; i<n-1; i++){
		double x1 = p.points[i].x - p.points[0].x;
		double y1 = p.points[i].y - p.points[0].y;

		double x2 = p.points[i+1].x - p.points[0].x;
		double y2 = p.points[i+1].y - p.points[0].y;

		double cross_product = x1*y2 - y1*x2;
		area += cross_product;
	}

	return abs(area/2);    //Return the absolute value of cross products divided by 2.
}

int main(){
	cout << "Enter the number of points of polygon " << endl;
	int n;
	cin >> n;

	Polygon p(n);

	cout << "Enter the co-ordinates of the polygon" << endl;

	for(int i=0; i<n; i++){
		cin >> p.points[i].x;
		cin >> p.points[i].y;
	}

	cout << "Area of Polygon is: " << areaPolygon(p, n) << endl;
	return 0;
}