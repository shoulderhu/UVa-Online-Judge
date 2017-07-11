#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, string> Map;

inline string getRoot(string s) {

	if (Map[s] == s) { return s; }
	else { return Map[s] = getRoot(Map[s]); }
}

int main() {

	int C, R;
	string name1, name2;

	while (cin >> C >> R && !(C == 0 && R == 0)) {

		Map.clear();

		for (int i = 0; i < C; ++i) {

			cin >> name1;
			Map[name1] = name1;
		}

		for (int i = 0; i < R; ++i) {

			cin >> name1 >> name2;
			name1 = getRoot(name1), name2 = getRoot(name2);
			Map[name2] = name1;
		}

		int size = 0;
		unordered_map<string, int> chain;

		for (auto iter = Map.begin(); iter != Map.end(); ++iter) {

			size = max(size, ++chain[getRoot(iter->second)]);
		}

		cout << size << endl;
	}

	return 0;
}
