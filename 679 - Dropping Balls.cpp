#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int l, D, I, P;

	cin >> l;

	for (int i = 0; i < l; ++i) {

		cin >> D >> I;
		P = 1;

		for (int j = 1; j < D; ++j) {

			if (I % 2 == 0) {

				P = P * 2 + 1;
				I /= 2;
			}
			else {

				P *= 2;
				I = (I + 1) / 2;
			}
		}

		cout << P << endl;
	}
	
	cin >> l;

	return 0;
}