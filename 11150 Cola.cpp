#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;

	while (cin >> N) {

		int drink = N;

		while (N >= 3) {

			int temp = N / 3;

			drink += temp;
			N = N % 3 + temp;
		}

		if (N == 2) { drink++; }

		cout << drink << endl;
	}

	return 0;
}