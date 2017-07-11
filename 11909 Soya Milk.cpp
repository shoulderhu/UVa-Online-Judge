#include <iostream>
#include <iomanip>
#include <cmath>
#define PI acos(-1.0)

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int l, w, h, degree;

	while (cin >> l >> w >> h >> degree) {

		double Tan = tan(degree*PI / 180);

		if (Tan > (double)h / l) { cout << fixed << setprecision(3) << w*h*h / Tan*0.5; }
		else { cout << fixed << setprecision(3) << l*w*h - l*w*l*Tan*0.5; }
		
		cout << " mL" << endl;
	}

	return 0;
}