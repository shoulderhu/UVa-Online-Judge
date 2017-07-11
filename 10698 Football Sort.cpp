#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, G, HScore, AScore;
	char dash;
	bool isBL = false;	
	struct squad { int point = 0, game = 0, score = 0, suffer = 0, goalDifference; };
	string name, home, away;

	while (cin >> T >> G && T != 0 || G != 0) {

		if (isBL == false) { isBL = true; }
		else { cout << endl; }

		int position = 0, p = 0;		
		unordered_map<string, struct squad> Map;

		for (int i = 0; i < T; ++i) {

			cin >> name;
			Map[name];
		}

		for (int i = 0; i < G; ++i) {

			cin >> home >> HScore >> dash >> AScore >> away;

			++Map[home].game, ++Map[away].game;
			Map[home].score += HScore, Map[home].suffer += AScore;
			Map[away].score += AScore, Map[away].suffer += HScore;

			if (HScore > AScore) { Map[home].point += 3; }
			else if(HScore < AScore){ Map[away].point += 3; }
			else { ++Map[home].point, ++Map[away].point; }
		}

		for (auto iter = Map.begin(); iter != Map.end(); ++iter) {

			iter->second.goalDifference = iter->second.score - iter->second.suffer;			
		}

		vector<pair<string, struct squad>> Vec(Map.begin(), Map.end());

		sort(Vec.begin(), Vec.end(), [](pair<string, struct squad> a, pair<string, struct squad> b) {
		
			if (a.second.point != b.second.point) {
				
				return a.second.point > b.second.point; 
			}
			else if (a.second.goalDifference != b.second.goalDifference) {

				return a.second.goalDifference > b.second.goalDifference;
			}
			else if (a.second.score != b.second.score) {
				
				return a.second.score > b.second.score; 
			}
			else {

				transform(a.first.begin(), a.first.end(), a.first.begin(), ::tolower);
				transform(b.first.begin(), b.first.end(), b.first.begin(), ::tolower);

				return a.first < b.first;
			}			
		});

		for (int i = 0; i < Vec.size(); ++i) {

			if (i != 0 && Vec[i].second.point == Vec[i - 1].second.point
			           && Vec[i].second.goalDifference == Vec[i - 1].second.goalDifference
			           && Vec[i].second.score == Vec[i - 1].second.score) {
			
				cout << "   ";
				++p;
			}
			else { 
				
				cout << setw(2) << ++position + p << ".";
				position += p, p = 0;
			}

			cout << setw(16) << Vec[i].first << setw(4) << Vec[i].second.point
			     << setw(4) << Vec[i].second.game << setw(4) << Vec[i].second.score
			     << setw(4) << Vec[i].second.suffer << setw(4) << Vec[i].second.goalDifference;
			
			if (Vec[i].second.game == 0) { cout << "    N/A"; }
			else {

				cout << " " << setw(6) << fixed << setprecision(2)
				   	 << Vec[i].second.point*100.0 / (3 * Vec[i].second.game);
			}
						
			cout << endl;
		}
	}

	return 0;
}