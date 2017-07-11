#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct team {
	
	int point = 0, win = 0, tie = 0, lose = 0, game = 0;
	int goalDifference = 0, goalScored = 0, goalAgainst = 0;
}football;

bool mySort(pair<string, struct team> &a, pair<string, struct team> &b) {

	if (a.second.point != b.second.point) { return a.second.point > b.second.point; }
	else if (a.second.win != b.second.win) { return a.second.win > b.second.win; }
	else if (a.second.goalDifference != b.second.goalDifference) { return a.second.goalDifference > b.second.goalDifference; }
	else if (a.second.goalScored != b.second.goalScored) { return a.second.goalScored > b.second.goalScored; }
	else if (a.second.game != b.second.game) { return a.second.game < b.second.game; }
	else {
		
		string A = a.first, B = b.first;

		transform(A.begin(), A.end(), A.begin(), ::tolower);
		transform(B.begin(), B.end(), B.begin(), ::tolower);
		
		return A < B;		
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, T, G, g1, g2;
	string Tournament, line, name, n1, n2;
	stringstream ss;

	cin >> N, cin.ignore();

	for (int i = 1; i <= N; ++i) {

		if (i > 1) { cout << endl; }

		getline(cin, Tournament);
		cin >> T, cin.ignore();

		map<string, struct team> Team;

		for (int j = 1; j <= T; ++j) {

			getline(cin, name);
			Team[name] = football;
		}

		cin >> G, cin.ignore();

		for (int j = 1; j <= G; ++j) {

			getline(cin, line);

			for (int k = 0; k < line.size(); ++k) {

				if (line[k] == '#' || line[k] == '@') { line[k] = ' '; }
				else if (line[k] == ' ') { line[k] = '#'; }
			}

			ss.clear(), ss << line, ss >> n1 >> g1 >> g2 >> n2;

			for (int k = 0; k < n1.size(); ++k) { if (n1[k] == '#') { n1[k] = ' '; } }
			for (int k = 0; k < n2.size(); ++k) { if (n2[k] == '#') { n2[k] = ' '; } }

			if (g1 > g2) { Team[n1].point += 3, ++Team[n1].win, ++Team[n2].lose; }
			else if (g1 < g2) { ++Team[n1].lose, Team[n2].point += 3, ++Team[n2].win; }
			else { ++Team[n1].point, ++Team[n1].tie, ++Team[n2].point, ++Team[n2].tie; }

			++Team[n1].game, ++Team[n2].game;
			Team[n1].goalScored += g1, Team[n2].goalScored += g2;
			Team[n1].goalAgainst += g2, Team[n2].goalAgainst += g1;					
		}

		for (auto iter = Team.begin(); iter != Team.end(); ++iter) {

			iter->second.goalDifference = iter->second.goalScored - iter->second.goalAgainst;
		}

		vector<pair<string, struct team>> Vector(Team.begin(), Team.end());
		sort(Vector.begin(), Vector.end(), mySort);

		cout << Tournament << endl;

		for (int j = 0; j < Vector.size(); ++j) {

			cout << j + 1 << ") " << Vector[j].first << " " << Vector[j].second.point << "p, "
				 << Vector[j].second.game << "g (" << Vector[j].second.win << "-" << Vector[j].second.tie
				 << "-" << Vector[j].second.lose << "), " << Vector[j].second.goalDifference << "gd ("
				 << Vector[j].second.goalScored << "-" << Vector[j].second.goalAgainst << ")\n";			
		}
	}

	return 0;
}
