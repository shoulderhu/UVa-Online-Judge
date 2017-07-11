#include <iostream>
#include <iomanip>
#include <cmath>
#define PI acos(-1.0)

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	double F, sin1 = sin(PI * 108 / 180), sin2 = sin(PI * 63 / 180);

	while (cin >> F) {

		cout << fixed << setprecision(10) << F * sin1 / sin2 << endl;
	}
	
	return 0;
}