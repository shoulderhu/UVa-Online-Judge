#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct contestant {

	int problem = 0, time = 0;
	set<int> AC;
	map<int, int> penalty;
};

bool mySort(pair<int, struct contestant> &a, pair<int, contestant> &b) {

	if (a.second.problem != b.second.problem) { return a.second.problem > b.second.problem; }
	else if (a.second.time != b.second.time) { return a.second.time < b.second.time; }
	else { return a.first < b.first; }	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace, c, p, t;
	char L;
	string line;
		
	cin >> kace, cin.ignore(), cin.ignore();
	
	for (int i = 1; i <= kace; ++i) {

		if (i > 1) { cout << endl; }
						
		map<int, struct contestant> scoreBoard;
		
		while (getline(cin, line) && line.size() > 0) {

			stringstream ss(line);
			ss >> c >> p >> t >> L;
			
			if (L == 'C') {
				
				if (scoreBoard[c].AC.find(p) == scoreBoard[c].AC.end()) {

					++scoreBoard[c].problem;
					scoreBoard[c].time += scoreBoard[c].penalty[p] * 20 + t;
					scoreBoard[c].AC.insert(p);
				}
			}
			else if (L == 'I') { ++scoreBoard[c].penalty[p]; }
			else { scoreBoard[c]; }
		}

		vector<pair<int, struct contestant>> Vector(scoreBoard.begin(), scoreBoard.end());
		sort(Vector.begin(), Vector.end(), mySort);

		for (auto iter = Vector.begin(); iter != Vector.end(); ++iter) {

			cout << iter->first << " " << iter->second.problem << " " << iter->second.time << endl;
		}		
	}

	return 0;
}