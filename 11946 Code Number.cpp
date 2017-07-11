#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	string line;

	cin >> T, cin.ignore();

	for (int i = 0; i < T; ++i) {

		if (i > 0) { cout << endl; }

		while (getline(cin, line) && line != "") {

			for (int j = 0; j < line.size(); ++j) {

				if (isdigit(line[j]) == 0) { cout << line[j]; }
				else { 
					
					switch (line[j]) {

					case '0': cout << "O"; break;
					case '1': cout << "I"; break;
					case '2': cout << "Z"; break;
					case '3': cout << "E"; break;
					case '4': cout << "A"; break;
					case '5': cout << "S"; break;
					case '6': cout << "G"; break;
					case '7': cout << "T"; break;
					case '8': cout << "B"; break;
					case '9': cout << "P"; break;
					}
				}
			}

			cout << endl;
		}
	}

	return 0;
}