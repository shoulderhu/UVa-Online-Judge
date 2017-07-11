#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	bool isBL = false;
	string line, word;
	
	while (cin >> n) {

		if (isBL == false) { isBL = true; }
		else { cout << endl; }

		bool isThere = false;
		map<string, int> Map;

		while (getline(cin, line) && line != "EndOfText") {
						
			for (int i = 0; i < line.size(); ++i) {

				if (isalpha(line[i]) == 0) { line[i] = ' '; }
			}

			transform(line.begin(), line.end(), line.begin(), ::tolower);

			stringstream ss(line);
			while (ss >> word) { ++Map[word]; }
		}

		for (auto iter = Map.begin(); iter != Map.end(); ++iter) {

			if (iter->second == n) { 
				
				isThere = true;
				cout << iter->first << endl; 
			}
		}

		if (isThere == false) { cout << "There is no such word." << endl; }
	}

	return 0;
}