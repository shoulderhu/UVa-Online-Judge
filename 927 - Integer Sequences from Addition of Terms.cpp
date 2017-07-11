#include <iostream>
#include <cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int C, i, d, k, m;
	long long int c[21], sum;

	cin >> C;

	for (int j = 0; j < C; ++j) {

		cin >> i;

		for (int l = 0; l <= i; ++l) {

			cin >> c[l];
		}

		cin >> d >> k;
		sum = 0;

		for (int l = 1; ; ++l) {

			if ((sum += l*d) >= k) {

				m = l;
				break;
			}
		}

		sum = 0; 

		for (int l = 0; l <= i; ++l) {

			sum += c[l] * pow(m, l);
		}

		cout << sum << "\n";
	}
	
	return 0;
}