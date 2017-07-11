#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	string line;

	cin >> T, cin.ignore();

	for (int i = 1; i <= T; ++i) {

		getline(cin, line);

		int length = line.size();
		double column = sqrt((double)length);

		if (column != (int)column) {
			
			cout << "INVALID" << endl;
			continue;
		}

		for (int j = 0; j < column; ++j) {

			for (int k = j; k < length; k += column) {

				cout << line[k];
			}
		}

		cout << endl;
	}

	return 0;
}