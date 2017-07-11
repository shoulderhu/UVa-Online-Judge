#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.141592653589793

using namespace std;

inline double length(double x1, double y1, double x2, double y2) {

	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	double x[3], y[3];

	while (cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2]) {

		double a = length(x[0], y[0], x[1], y[1]);
		double b = length(x[1], y[1], x[2], y[2]);
		double c = length(x[0], y[0], x[2], y[2]);
		double s = (a + b + c) / 2, triangle = sqrt(s*(s - a)*(s - b)*(s - c));
		double R2 = a*b*c / (2 * triangle);

		cout << fixed << setprecision(2) << R2 * PI << endl;
	}

	return 0;
}