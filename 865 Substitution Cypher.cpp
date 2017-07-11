#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace;
	string plaintext, substitution, line;

	cin >> kace, cin.ignore(), cin.ignore();

	for (int i = 0; i < kace; ++i) {

		if (i > 0) { cout << endl; }

		getline(cin, plaintext), getline(cin, substitution);
		
		map<char, char> Map;

		for (int j = 0; j < plaintext.size() || j < substitution.size(); ++j) {

			if (j >= plaintext.size()) { Map[' '] = substitution[j]; }
			else if (j >= substitution.size()) { Map[plaintext[j]] = ' '; }
			else{ Map[plaintext[j]] = substitution[j]; }			
		}
		
		cout << substitution << endl;
		cout << plaintext << endl;
		
		while (getline(cin, line) && line != "") {

			for (int j = 0; j < line.size(); ++j) {

				if (Map.find(line[j]) == Map.end()) { cout << line[j]; }
				else { cout << Map[line[j]]; }
			}

			cout << endl;
		}
	}

	return 0;
}