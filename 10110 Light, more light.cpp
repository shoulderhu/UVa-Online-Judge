#include <iostream>
#include <cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	double n;

	while (cin >> n && n != 0) {

		double root = sqrt(n);
		root == (int)root ? cout << "yes\n" : cout << "no\n";
	}

	return 0;
}