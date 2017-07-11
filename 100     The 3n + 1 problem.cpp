#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int i, j, k;

	while (cin >> i >> j) {

		int max = 0;

		cout << i << " " << j << " ";

		if (i > j) { swap(i, j); }

		for (k = i; k <= j; k++) {

			int cycle = 1, kCp = k;

			while (kCp != 1) {

				cycle++;

				if (kCp % 2 != 0) { kCp = 3 * kCp + 1; }
				else { kCp /= 2; }
			}

			if (cycle > max) { max = cycle; }
		}

		cout << max << endl;
	}
	
	return 0;
}