#include <iostream>
#include <cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	double S, D;

	while (cin >> S >> D) {

		cout << (long long int)ceil((-1 + sqrt(1.0 - 4 * (S - S*S - 2 * D))) / 2) << endl;
	}

	return 0;
}