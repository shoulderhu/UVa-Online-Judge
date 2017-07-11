#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

inline bool mySort(pair<char, int> &a, pair<char, int> &b) {

	return a.second > b.second;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string line[2];

	while (cin >> line[0] >> line[1]) {
		
		map<char, int> Map[2];

		for (int i = 0; i < line[0].size(); ++i) {

			++Map[0][line[0][i]], ++Map[1][line[1][i]];
		}

		bool isNo = false;
		vector<pair<char, int>> Vector0(Map[0].begin(), Map[0].end());
		vector<pair<char, int>> Vector1(Map[1].begin(), Map[1].end());

		sort(Vector0.begin(), Vector0.end(), mySort);
		sort(Vector1.begin(), Vector1.end(), mySort);
		
		for (int i = 0; i < Vector0.size(); ++i) {

			if (Vector0[i].second != Vector1[i].second) { 
				
				cout << "NO" << endl; 
				isNo = true;
				break;
			}
		}

		if (isNo == false) { cout << "YES" << endl; }
	}
	
	return 0;
}
