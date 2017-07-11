#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

char c, x, y;
char order[21];
bool isFirst = true;
string line;
stringstream ss;
map<char, int> arrow;
unordered_map<char, bool> isVisit;
unordered_map<char, vector<char>> Map;

inline void DFS(int i) {

	for (auto iter = arrow.begin(); iter != arrow.end(); ++iter) {
	
		if (isVisit[iter->first] == false && iter->second == 0) {
						
			order[i] = iter->first;			
			
			if (i == arrow.size()) { 
				
				for (int j = 1; j <= arrow.size(); ++j) {

					cout << order[j];
				}

				cout << '\n'; 
				return;
			}

			isVisit[iter->first] = true;
			
			for (auto jter = Map[iter->first].begin(); jter != Map[iter->first].end(); ++jter) {

				--arrow[*jter];
			}

			DFS(i + 1);
			isVisit[iter->first] = false;

			for (auto jter = Map[iter->first].begin(); jter != Map[iter->first].end(); ++jter) {

				++arrow[*jter];
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	while (getline(cin, line)) {

		if (isFirst) { isFirst = false; }
		else { cout << '\n'; }

		arrow.clear(), isVisit.clear(), Map.clear();
		ss.clear(), ss << line;

		while (ss >> c) { 
			
			arrow[c] = 0;
			isVisit[c] = false;
		}

		getline(cin, line);
		ss.clear(), ss << line;

		while (ss >> x >> y) { 
			
			++arrow[y];
			Map[x].push_back(y);
		}
		
		DFS(1);
	}

	return 0;
}