#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int length;
	struct kwic { string keyword, title; }KWIC;
	string line;
	set<string> WTI;
	vector<struct kwic> Vector;

	while (cin >> line && line != "::") { WTI.insert(line); }

	cin.ignore(1024, '\n');

	while (getline(cin, line)) {
				
		transform(line.begin(), line.end(), line.begin(), ::tolower);
		string lineCp = line;
		lineCp += " ";
		
		for (int i = 0; i < lineCp.size(); i += length + 1) {
						
			size_t pos = lineCp.find(' ', i);			
			length = pos - i, KWIC.keyword = lineCp.substr(i, length);

			if (WTI.find(KWIC.keyword) == WTI.end()) { 
				
				string lineCpy = line;

				transform(KWIC.keyword.begin(), KWIC.keyword.end(), KWIC.keyword.begin(), ::toupper);
				lineCpy.replace(i, KWIC.keyword.size(), KWIC.keyword);
				KWIC.title = lineCpy, Vector.push_back(KWIC);
			}
		}				
	}

	stable_sort(Vector.begin(), Vector.end(), [](struct kwic a, struct kwic b) {

		return a.keyword < b.keyword;
	});

	for (int i = 0; i < Vector.size(); ++i) { cout << Vector[i].title << endl; }
	
	return 0;
}