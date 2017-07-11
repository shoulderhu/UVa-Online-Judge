#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	char letter;
	string line, word;

	while (getline(cin, line) && line != "*") {

		bool isTautogram = true;
		stringstream ss(line);
		
		ss >> word, letter = tolower(word[0]);

		while (ss >> word) {

			if (letter != tolower(word[0])) {

				isTautogram = false;
				break;
			}
		}

		isTautogram == true ? cout << "Y" << endl : cout << "N" << endl;
	}

	return 0;
}