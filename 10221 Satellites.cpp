#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#define PI acos(-1.0)

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	double s, a;
	string str;

	while (cin >> s >> a >> str) {

		if (str == "min") { a /= 60; }
		if (a > 180) { a = 360 - a; }
		
		cout << fixed << setprecision(6) << a*PI / 180 * (6440 + s)
			 << " " << sin(a*PI / 360) * 2 * (6440 + s) << endl;
	}

	return 0;
}