#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace = 0, lcs[500][500];
	string line[2], word;
	stringstream ss;

	while (getline(cin, line[0])) {

		getline(cin, line[1]);

		cout << setw(2) << ++kace << ". ";

		if (line[0] == "" || line[1] == "") { 
			
			cout << "Blank!" << endl; 
			continue;
		}

		vector<string> Vec[2];
		
		for (int j = 0; j < 2; ++j) {

			for (int i = 0; i < line[j].size(); ++i) {

				if (isalpha(line[j][i]) == 0 && isdigit(line[j][i]) == 0) { 
					
					line[j][i] = ' ';
				}
			}

			ss.clear(), ss << line[j];
			while (ss >> word) { Vec[j].push_back(word); }
		}

		lcs[0][0] = 0;
		for (int j = 1; j <= Vec[0].size(); ++j) { lcs[j][0] = 0; }
		for (int j = 1; j <= Vec[1].size(); ++j) { lcs[0][j] = 0; }

		for (int j = 0; j < Vec[0].size(); ++j) {

			for (int i = 0; i < Vec[1].size(); ++i) {

				if (Vec[0][j] == Vec[1][i]) {

					lcs[j + 1][i + 1] = lcs[j][i] + 1;
				}
				else { lcs[j + 1][i + 1] = max(lcs[j][i + 1], lcs[j + 1][i]); }
			}
		}

		cout << "Length of longest match: " << lcs[Vec[0].size()][Vec[1].size()] << endl;
	 }

	return 0;
}