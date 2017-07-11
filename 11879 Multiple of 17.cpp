#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string integer;

	while (cin >> integer && integer != "0") {

		int result = 0;

		for (int i = 0; i < integer.size(); ++i) {

			result = (result * 10 + (integer[i] - '0')) % 17;
		}

		result == 0 ? cout << "1\n" : cout << "0\n";
	}

	return 0;
}