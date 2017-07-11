#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, S, A, F, s, a;

	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> S >> A >> F;

		vector<int> Street, Avenue;

		for (int j = 0; j < F; ++j) {

			cin >> s >> a;
			Street.push_back(s);
			Avenue.push_back(a);
		}

		sort(Street.begin(), Street.end());
		sort(Avenue.begin(), Avenue.end());

		cout << "(Street: " << Street[(F - 1) / 2]
			 << ", Avenue: " << Avenue[(F - 1) / 2]
			 << ")" << endl;
	}

	return 0;
}