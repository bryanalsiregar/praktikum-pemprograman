#include<iostream>
#include<math.h>

using namespace std;

int main() {
	float a, b, c, disc, x_1, x_2;
	cin >> a >> b >> c;
	
	disc = pow(b,2)-4*a*c;
	
	if (disc > 0) {
		cout << "there are two distinct real root: " << endl;
		cout << "x_1: " << (-b+sqrt(disc))/(2*a) << endl;
		cout << "x_2: " << (-b-sqrt(disc))/(2*a) << endl;
	}
	if (disc == 0) {
		cout << "there are exactly one real root: " << endl;
		cout << "x: " << (-b)/(2*a) << endl;
	}
	if (disc < 0) {
		cout << "there are no real roots (the roots are complex)" <<endl;
	}
	
	return 0;
}
