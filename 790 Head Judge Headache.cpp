#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	struct log {

		int No, time;
		char letter, status;
	}Log;
	struct team {

		int No, time = 0, problem = 0;
		unordered_set<char> AC;
		unordered_map<char, int> WA;
	}TEAM;
	string line, sub;
	
	cin >> T, cin.ignore(), cin.ignore();

	for (int j = 0; j < T; ++j) {

		if (j > 0) { cout << endl; }

		int rank = 0, size = 0, r = 0;
		vector<struct log> list;
		vector<struct team> Vec;
		unordered_map<int, bool> Map;
		
		while (getline(cin, line) && line != "") {

			stringstream ss(line);

			ss >> Log.No >> Log.letter >> sub >> Log.status;
			Log.time = stoi(sub.substr(0, 1), nullptr, 10) * 60 + stoi(sub.substr(2, 2), nullptr, 10);
			list.push_back(Log);
		}

		sort(list.begin(), list.end(), [](struct log a, struct log b) {
		
			if (a.time != b.time) { return a.time < b.time; }
			else { return a.status < b.status; }
		});

		for (auto iter = list.begin(); iter != list.end(); ++iter) {
			
			auto pos = find_if(Vec.begin(), Vec.end(), [&iter](struct team t) {
				
				return t.No == iter->No;
			});

			size = max(size, iter->No);
			
			if (pos == Vec.end()) {
					
				struct team Team;

				if (iter->status == 'Y') {
										
					++Team.problem;
					Team.AC.insert(iter->letter);
					Team.time += iter->time;
				}
				else { ++Team.WA[iter->letter]; }

				Team.No = iter->No, Vec.push_back(Team), Map[iter->No] = true;
			}
			else {

				if (iter->status == 'Y') {

					if (pos->AC.find(iter->letter) == pos->AC.end()) {
						
						++pos->problem,	pos->AC.insert(iter->letter);						
						pos->time += pos->WA[iter->letter] * 20 + iter->time;
					}
				}
				else { ++pos->WA[iter->letter]; }
			}
		}

		for (int i = 1; i <= size; ++i) {

			if (Map[i] == false) { TEAM.No = i, Vec.push_back(TEAM); }
		}

		sort(Vec.begin(), Vec.end(), [](struct team a, struct team b) {

			if (a.problem != b.problem) { return a.problem > b.problem; }
			else if (a.time != b.time) { return a.time < b.time; }
			else { return a.No < b.No; }
		});

		cout << "RANK TEAM PRO/SOLVED TIME" << endl;

		for (int i = 0; i < Vec.size(); ++i) {

			if (i != 0 && Vec[i].time == Vec[i - 1].time && Vec[i].problem == Vec[i - 1].problem) {

				cout << setw(4) << rank;
				++r;
			}
			else { 
				
				cout << setw(4) << ++rank + r;
				rank += r, r = 0;
			}

			cout << " " << setw(4) << Vec[i].No;

			if (Vec[i].problem != 0) {

				cout << " " << setw(4) << Vec[i].problem << "      ";
				cout << " " << setw(4) << Vec[i].time;
			}

			cout << endl;
		}
	}

	return 0;
}