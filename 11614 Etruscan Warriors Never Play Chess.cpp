#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace;
	long long int n;

	cin >> kace;

	for (int i = 0; i < kace; ++i) {

		cin >> n;
		cout << fixed << setprecision(0) << floor((-1 + sqrt(1.0 + 8 * n)) / 2) << endl;
	}

	return 0;
}