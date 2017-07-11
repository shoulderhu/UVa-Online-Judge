#include <iostream>
#include <cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	long long int num;
	
	while (cin >> num && num >= 0) {

		for (int i = 2; i <= sqrt((double)num); ++i) {

			while (num%i == 0) {

				cout << "    " << i << endl;
				num /= i;
			}
		}

		cout << "    " << num << endl;
		cout << endl;
	}

	return 0;
}
