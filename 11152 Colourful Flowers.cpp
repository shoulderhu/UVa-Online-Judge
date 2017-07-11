#include <iostream>
#include <iomanip>
#include <cmath>
#define PI acos(-1.0)

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;

	while (cin >> a >> b >> c) {

		double s = (a + b + c) / 2.0, violet = sqrt(s*(s - a)*(s - b)*(s - c)),
			   R = a*b*c / violet / 4, r = violet / s, rose = r*r*PI;
		
		cout << fixed << setprecision(4) << R*R*PI - violet << " " << violet - rose << " "
			                                                       << rose << endl;
	}

	return 0;
}
