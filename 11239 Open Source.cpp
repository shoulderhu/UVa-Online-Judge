#include <iostream>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct wall {

	int student = 0;
	string name;	
};

bool mySort(struct wall a, struct wall b) {

	if (a.student != b.student) { return a.student > b.student; }
	else { return a.name < b.name; }
}

int main() {
		
	string line;
	
	while (getline(cin, line) && line != "0") {

		string p = line;
		vector<struct wall> Vector;
		map<string, set<string>> project;
		map<string, int> Map;
		
		project[p];

		while (getline(cin, line) && line != "1") {

			if (isupper(line[0]) != 0) { p = line, project[p]; }
			else { 
				
				if (project[p].find(line) == project[p].end()) {

					++Map[line], project[p].insert(line);
				}
			}
		}

		for (auto iter = project.begin(); iter != project.end(); ++iter) {

			struct wall Wall;
			Wall.name = iter->first;

			for (auto jter = iter->second.begin(); jter != iter->second.end(); ++jter) {

				if (Map[*jter] == 1) { ++Wall.student; }
			}

			Vector.push_back(Wall);
		}

		sort(Vector.begin(), Vector.end(), mySort);

		for (auto iter = Vector.begin(); iter != Vector.end(); ++iter) {

			cout << iter->name << " " << iter->student << endl;
		}
	}

	return 0;
}