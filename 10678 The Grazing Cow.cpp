#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 2*acos(0.0)

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	double D, L;

	cin >> N;

	for (int i = 1; i <= N; ++i) {

		cin >> D >> L;
				
		double  c = D / 2, a = L / 2, b = sqrt((double)a*a - c*c);
		
		cout << fixed << setprecision(3) << a * b * PI << endl;
	}

	return 0;
}