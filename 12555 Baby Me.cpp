#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, a;
	string line;

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> a;
		getline(cin, line);

		int b = 0;

		for (int j = 0; j < line.size(); ++j) {

			if (isdigit(line[j]) != 0) {

				b = line[j] - '0';
				break;
			}
		}

		cout << "Case " << i << ": " << a*0.5 + b*0.05 << endl;
	}

	return 0;
}