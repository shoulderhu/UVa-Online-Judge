#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, m, n;
	string line;

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> m >> n;
		
		int error = 0;
		vector<map<char, int>> Map(n);		 
		vector<vector<pair<char, int>>> Vector;

		for (int j = 1; j <= m; ++j) {

			cin >> line;
			for (int k = 0; k < n; ++k) { ++Map[k][line[k]]; }			
		}		

		for (int j = 0; j < n; ++j) {

			vector<pair<char, int>> temp(Map[j].begin(), Map[j].end());
			Vector.push_back(temp);
		}

		for (int j = 0; j < n; ++j) {

			sort(Vector[j].begin(), Vector[j].end(), [](pair<char, int>& a, pair<char, int>& b) {
			
				if (a.second != b.second) { return a.second > b.second; }
				else { return a.first < b.first; }
			});

			cout << Vector[j].begin()->first;
			error += m - Vector[j].begin()->second;
		}

		cout << endl << error << endl;
	}

	return 0;
}
