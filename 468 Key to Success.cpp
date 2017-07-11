#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace;
	string line;

	cin >> kace;

	for (int i = 0; i < kace; ++i) {

		if (i > 0) { cout << endl; }
		
		unordered_map<char, char> Map;
		unordered_map<char, int> text, Text;
		
		cin >> line;
		for (int j = 0; j < line.size(); ++j) { ++text[line[j]]; }

		cin >> line;
		for (int j = 0; j < line.size(); ++j) { ++Text[line[j]]; }

		vector<pair<char, int>> t(text.begin(), text.end()), T(Text.begin(), Text.end());

		sort(t.begin(), t.end(), [](pair<char, int> &a, pair<char, int> &b) {
		
			return a.second > b.second;
		});

		sort(T.begin(), T.end(), [](pair<char, int> &a, pair<char, int> &b) {

			return a.second > b.second;
		});

		for (int j = 0; j < t.size(); ++j) { Map[T[j].first] = t[j].first; }

		for (int j = 0; j < line.size(); ++j) { cout << Map[line[j]]; }
		cout << endl;
	}

	return 0;
}