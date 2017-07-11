#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	struct street { string from, to; }Street;
	string identifer[2], line;
	stringstream ss;
	
	while (cin >> identifer[0] && identifer[0] != "END") {
		
		cin.ignore();

		bool isDetail = true;
		set<string> place;
		vector<struct street> Map1;
		map<string, set<string>> Map2;

		while (getline(cin, line) && line[0] != '*') {

			ss.clear(), ss << line, ss >> Street.from >> Street.to;				
			Map1.push_back(Street);
			place.insert(Street.from), place.insert(Street.to);
		}
		
		cin >> identifer[1], cin.ignore();

		while (getline(cin, line) && line[0] != '*') {

			ss.clear(), ss << line, ss >> Street.from >> Street.to;
			Map2[Street.from].insert(Street.to);
			Map2[Street.to].insert(Street.from);
		}
		
		for (auto iter = Map1.begin(); iter != Map1.end(); ++iter) {
			
			bool isConnect = false;
			set<string> isVisit;
			queue<string> BFS;
			BFS.push(iter->from);

			while (BFS.empty() == false) {

				int length = BFS.size(); 

				for (int i = 0; i < length; ++i) {

					string temp = BFS.front();
					BFS.pop();

					if (isVisit.find(temp) == isVisit.end()) {

						if (temp == iter->to) { isConnect = true; break; }
						else {

							isVisit.insert(temp);
							for (auto jter = Map2[temp].begin(); jter != Map2[temp].end(); ++jter) { 
																
								if (place.find(*jter) == place.end()) { BFS.push(*jter); }
								else if (*jter == iter->to) { isConnect = true; break; }
							}
						}						
					}
				}
				
				if (isConnect == true) { break; }
			}

			if (isConnect == false) { isDetail = false; break; }
		}
			
		if (isDetail == true) { cout << "YES: " << identifer[1] << " is a more detailed version of " << identifer[0] << endl; }
		else{ cout << "NO: " << identifer[1] << " is not a more detailed version of " << identifer[0] << endl; }
	}

	return 0;
}
