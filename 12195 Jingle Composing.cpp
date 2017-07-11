#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string line;
	
	while (cin >> line && line != "*") {

		int right = 0;
		double sum = 0;

		for (int i = 1; i < line.size(); ++i) {

			if (line[i] == '/') {

				if (sum == 1) { ++right; }
				sum = 0;
			}
			else if (line[i] == 'W') { sum += 1; }
			else if (line[i] == 'H') { sum += 0.5; }
			else if (line[i] == 'Q') { sum += 0.25; }
			else if (line[i] == 'E') { sum += 0.125; }
			else if (line[i] == 'S') { sum += 0.0625; }
			else if (line[i] == 'T') { sum += 0.03125; }
			else { sum += 0.015625; }
		}

		cout << right << endl;
	}

	return 0;
}