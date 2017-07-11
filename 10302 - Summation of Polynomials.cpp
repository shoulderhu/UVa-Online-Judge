#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	long long int x;

	while (cin >> x) {

		cout << x * x * (x + 1) * (x + 1) / 4 << endl;
	}

	return 0;
}
