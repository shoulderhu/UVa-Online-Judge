#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, P, p[1000], MIN;
	bool isFirst;
	string line, neighbor;
	stringstream ss;

	cin >> N, cin.ignore();

	for (int i = 0; i < N; ++i) {

		cin >> P, cin.ignore();
		MIN = P, isFirst = true;

		for (int j = 0; j < P; ++j) {

			p[j] = 0;
			getline(cin, line);
			ss.clear(), ss << line;			
			while (ss >> neighbor) { ++p[j]; }
			MIN = min(MIN, p[j]);
		}

		for (int j = 0; j < P; ++j) {

			if (p[j] == MIN) {

				if (isFirst) { isFirst = false; }
				else { cout << ' '; }
				cout << j + 1;
			}
		}

		cout << '\n';
	}

	return 0;
}