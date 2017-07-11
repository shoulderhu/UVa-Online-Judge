#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int Case;
char c;
char order[21];
bool isNO;
string line, constraint;
stringstream ss;
map<char, int> arrow;
unordered_map<char, bool> isVisit;
unordered_map<char, vector<char>> edge;

inline void DFS(int o) {

	for (auto iter = arrow.begin(); iter != arrow.end(); ++iter) {

		if (isVisit[iter->first] == false && iter->second == 0) {

			order[o] = iter->first;

			if (o == arrow.size()) {

				for (int i = 1; i <= arrow.size(); ++i) {

					if (i > 1) { cout << ' '; }
					cout << order[i];
				}

				cout << '\n';
				isNO = false;
				return;
			}
			
			isVisit[iter->first] = true;

			for (auto jter = edge[iter->first].begin(); jter != edge[iter->first].end(); ++jter) {

				--arrow[*jter];
			}

			DFS(o + 1);
			isVisit[iter->first] = false;

			for (auto jter = edge[iter->first].begin(); jter != edge[iter->first].end(); ++jter) {

				++arrow[*jter];
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	cin >> Case, cin.ignore();

	for (int i = 0; i < Case; ++i) {

		if (i > 0) { cout << '\n'; }
		arrow.clear(), isVisit.clear(), edge.clear();
		isNO = true;

		cin.ignore();
		getline(cin, line);
		ss.clear(), ss << line;

		while (ss >> c) {

			arrow[c] = 0;
			isVisit[c] = false;
		}

		getline(cin, line);
		ss.clear(), ss << line;

		while (ss >> constraint) {

			++arrow[constraint[2]];
			edge[constraint[0]].push_back(constraint[2]);
		}

		DFS(1);
		if (isNO) { cout << "NO\n"; }
	}

	return 0;
}