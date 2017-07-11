#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	string line, word;
	stringstream ss;

	cin >> T, cin.ignore(), cin.ignore();

	for (int i = 1; i <= T; ++i) {
		
		if (i > 1) { cout << endl; }

		cout << "Case #" << i << ":" << endl;

		while (getline(cin, line) && line != "") {

			int pos = 0;
			ss.clear(), ss << line;

			while (ss >> word) {

				if (pos < word.size()) { 
					
					cout << word[pos];
					++pos;
				}				
			}

			cout << endl;
		}
	}

	return 0;
}