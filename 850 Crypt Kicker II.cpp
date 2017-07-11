#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace, size[] = { 3, 5, 5, 3, 5, 4, 3, 4, 3 };
	string line, decrypt = "the quick brown fox jumps over the lazy dog", word;
	
	cin >> kace, cin.ignore(), cin.ignore();

	for (int i = 1; i <= kace; ++i) {

		if (i > 1) { cout << endl; }

		bool isSolution = false;
		vector<string> Vector;
		map<char, char> Map;

		while (getline(cin, line) && line != "") {
						
			Vector.push_back(line);

			if (line.size() == 43 && isSolution == false) {

				bool isEncrypted = true;
				stringstream ss(line);
				vector<string> Word;
				Map.clear();

				while (ss >> word) { Word.push_back(word); }

				if (Word.size() != 9) { continue; }

				for (int j = 0; j < 9; ++j) {

					if (Word[j].size() != size[j]) {

						isEncrypted = false;
						break;
					}
				}

				if (isEncrypted == true) {

					for (int j = 0; j < 43; ++j) {
						
						if (Map.find(line[j]) != Map.end()) {
							
							if (Map[line[j]] != decrypt[j]) {

								isEncrypted = false;
								break;
							}						
						}
						else{ Map[line[j]] = decrypt[j]; }						
					}

					if (isEncrypted == true) { isSolution = true; }
				}				
			}
		}

		if (isSolution == false) { cout << "No solution." << endl; }
		else {

			for (auto iter = Vector.begin(); iter != Vector.end(); ++iter, cout << endl) {

				for (auto jter = iter->begin(); jter != iter->end(); ++jter) {

					cout << Map[*jter];
				}
			}
		}		
	}

	return 0;
}
