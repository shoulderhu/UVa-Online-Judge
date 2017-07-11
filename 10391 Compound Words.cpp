#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

string word;
set<string> Set;
vector<string> Vec;

int main() {

	Vec.reserve(120000);

	while (cin >> word) { Vec.push_back(word); }

	sort(Vec.begin(), Vec.end(), [](string &a, string &b) {
		
		return a.size() < b.size();
	});

	for (int i = 0; i < Vec.size(); ++i) {

		for (int j = 0; j < i; ++j) {

			if (Vec[i].compare(0, Vec[j].size(), Vec[j]) == 0 &&
				find(Vec.begin(), Vec.begin() + i, Vec[i].substr(Vec[j].size(), Vec[i].size() - Vec[j].size())) != Vec.begin() + i) {

				Set.insert(Vec[i]);
				break;
			}			
		}
	}

	for (auto iter = Set.begin(); iter != Set.end(); ++iter) {

		cout << *iter << endl;
	}

	return 0;
}