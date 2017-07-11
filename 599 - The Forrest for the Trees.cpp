#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int Case, x, y;
unordered_map<char, char> Map;

inline char getRoot(int c) {

	if (Map[c] == c) { return c; }
	else { return Map[c] = getRoot(Map[c]); }
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string pair;

	cin >> Case;

	for (int i = 0; i < Case; ++i) {

		x = 0, y = 0, Map.clear();

		while (cin >> pair && pair[0] != '*') {

			if (Map.find(pair[1]) == Map.end()) {

				Map[pair[1]] = pair[1];
			}

			if (Map.find(pair[3]) == Map.end()) {

				Map[pair[3]] = pair[3];
			}

			pair[1] = getRoot(pair[1]);
			pair[3] = getRoot(pair[3]);
			Map[pair[3]] = pair[1];
		}

		cin >> pair;

		for (int j = 0; j < pair.size(); j += 2) {

			if (Map.find(pair[j]) == Map.end()) { ++y; }
			else if (Map[pair[j]] == pair[j]) { ++x; }
		}
		
		cout << "There are " << x << " tree(s) and " << y << " acorn(s).\n";
	}
	
	return 0;
}