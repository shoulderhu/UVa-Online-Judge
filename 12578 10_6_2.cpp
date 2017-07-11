#include <iostream>
#include <iomanip>
#include <cmath>
#define PI acos(-1.0);

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, L;
	
	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> L;

		double R = L*0.2, circle = R*R*PI;

		cout << fixed << setprecision(2) << circle << " " << L*L*0.6 - circle << endl;
	}

	return 0;
}