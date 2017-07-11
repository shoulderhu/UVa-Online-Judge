#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <set>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string line, sen, word;
	
	while (getline(cin, line)) {
				
		for (int i = 0; i < line.size(); ++i) {

			if (isalpha(line[i]) != 0) { line[i] = tolower(line[i]); }
			else if (line[i] != '-') { line[i] = ' '; }
		}
		
		if (sen != "" && sen[sen.size() - 1] == '-') { sen.erase(sen.size() - 1, 1); }
		else { sen += " "; }
		sen += line;
	}

	stringstream ss(sen);
	set<string> dictionary;
	
	while (ss >> word) { dictionary.insert(word); }

	for (auto iter = dictionary.begin(); iter != dictionary.end(); ++iter) {

		cout << *iter << endl;
	}

	return 0;
}