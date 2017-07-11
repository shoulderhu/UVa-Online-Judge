#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace;
	string line;

	cin >> kace, cin.ignore();

	for (int i = 1; i <= kace; ++i) {

		getline(cin, line);

		map<char, int> Map;

		for (int i = 0; i < line.size(); ++i) {

			if (isalpha(line[i]) != 0) { ++Map[tolower(line[i])]; }
		}

		vector<pair<char, int>> Vec(Map.begin(), Map.end());

		stable_sort(Vec.begin(), Vec.end(), [](pair<char, int> a, pair<char, int> b) {
		
			return a.second > b.second;
		});

		int frequency = Vec.begin()->second;
		
		for (auto iter = Vec.begin(); iter != Vec.end(); ++iter) {

			if (iter->second == frequency) { cout << iter->first; }
			else { break; }
		}

		cout << endl;
	}

	return 0;
}