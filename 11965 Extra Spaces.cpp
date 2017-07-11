#include <iostream>
#include <string>
#include <iterator>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, N;
	string line;
	
	cin >> T, cin.ignore();

	for (int i = 0; i < T; ++i) {

		if (i > 0) { cout << endl; }

		cin >> N, cin.ignore();

		cout << "Case " << i + 1 << ":" << endl;

		for (int j = 0; j < N; ++j) {

			getline(cin, line);

			if (line.size() >= 2) {

				for (auto iter = ++line.begin(); iter != line.end(); ) {

					if (*iter == ' ' && *prev(iter) == ' ') {

						iter = line.erase(iter);
					}
					else { ++iter; }
				}
			}

			cout << line << endl;
		}
	}
	
	return 0;
}