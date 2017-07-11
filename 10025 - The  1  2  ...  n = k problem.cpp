#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int Case, k, n, sum;
	
	cin >> Case;

	for (int i = 0; i < Case; ++i) {

		if (i > 0) { cout << endl; }

		cin >> k;
		
		if (k == 0) { cout << 3 << endl; continue; }

		k = abs(k);
		n = ceil((-1 + sqrt(1 + 8.0 * k)) / 2);
		sum = n * (1 + n) / 2;

		if (k % 2 == 0) { while (sum % 2 != 0) { sum += ++n; } }
		else { while (sum % 2 == 0) { sum += ++n; } }

		cout << n << endl;
	}

	return 0;
}