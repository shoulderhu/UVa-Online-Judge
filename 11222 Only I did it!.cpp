#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, S, s;

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		int max = 0;
		set<int> friends[3];
		map<int, int> problem;

		for (int j = 0; j < 3; ++j) {

			cin >> S;

			for (int k = 1; k <= S; ++k) {

				cin >> s;
				friends[j].insert(s), ++problem[s];
			}
		}

		for (int j = 0; j < 3; ++j) {

			for (auto iter = friends[j].begin(); iter != friends[j].end(); ) {

				if (problem[*iter] > 1) { friends[j].erase(iter++); }
				else { ++iter; }
			}

			if (friends[j].size()>max) { max = friends[j].size(); }
		}

		cout << "Case #" << i << ":" << endl;

		for (int j = 0; j < 3; ++j) {

			if (friends[j].size() == max) {

				cout << j + 1 << " " << friends[j].size();

				for (auto iter = friends[j].begin(); iter != friends[j].end(); ++iter) {

					cout << " " << *iter;
				}

				cout << endl;
			}
		}
	}

	return 0;
}
