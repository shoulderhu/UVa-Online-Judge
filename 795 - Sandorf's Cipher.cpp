#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int hole[4][9] = { { 1, 3, 5, 10, 14, 19, 22, 29, 33 },
					   { 8, 11, 15, 18, 23, 26, 28, 31, 35 },
					   { 2, 6, 13, 16, 21, 25, 30, 32, 34 },
					   { 0, 4, 7, 9, 12, 17, 20, 24, 27 } };
	string line, group, message;


	while (getline(cin, line)) {

		message.clear();

		for (int i = 0; i < line.size(); i += 36) {

			group = line.substr(i, 36);

			for (int j = 0; j < 4; ++j) {

				for (int k = 0; k < 9; ++k) {

					message.push_back(group[hole[j][k]]);
				}
			}
		}

		reverse(message.begin(), message.end());
		while (message.back() == '#') { message.pop_back(); }
		cout << message << '\n';
	}

	return 0;
}