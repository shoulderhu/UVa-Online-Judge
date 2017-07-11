#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int grid[10][10];
char puzzle[10][10];

bool isEligible(int i, int j) {

	if (i == 0 || j == 0) { return true; }	
	else if (j > 0 && puzzle[i][j - 1] == '*') { return true; }
	else if (i > 0 && puzzle[i - 1][j] == '*') { return true; }	
	else { return false; }
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, c, puzzles = 0;	
	bool isBL = false;

	while (cin >> r && r != 0) {

		if (isBL == false) { isBL = true; }
		else { cout << endl; }

		cin >> c;

		for (int i = 0; i < r; ++i) {

			for (int j = 0; j < c; ++j) {

				cin >> puzzle[i][j];
			}
		}

		int integer = 0, length;
		string word;
		map<int, string> Map;

		for (int i = 0; i < r; ++i) {

			for (int j = 0; j < c; ++j) {

				if (puzzle[i][j] != '*' && isEligible(i, j) == true) { 
					
					grid[i][j] = ++integer; 
				}
			}
		}
		
		cout << "puzzle #" << ++puzzles << ":" << endl;
		cout << "Across" << endl;

		for (int i = 0; i < r; ++i) {

			for (int j = 0; j < c; j += length + 1) {

				if (puzzle[i][j] != '*') {
					
					length = 1,	word = "", word += puzzle[i][j];

					while (j + length < c && puzzle[i][j + length] != '*') { 
						
						word += puzzle[i][j + length], ++length;
					}

					cout << setw(3) << grid[i][j] << "." << word << endl;
				}
				else{ length = 0; }
			}			
		}
				
		cout << "Down" << endl;

		for (int i = 0; i < c; ++i) {

			for (int j = 0; j < r; j += length + 1) {

				if (puzzle[j][i] != '*') {

					length = 1, word = "", word += puzzle[j][i];

					while (j + length < r && puzzle[j + length][i] != '*') {

						word += puzzle[j + length][i], ++length;
					}

					Map[grid[j][i]] = word;
				}
				else { length = 0; }
			}
		}

		for (auto iter = Map.begin(); iter != Map.end(); ++iter) {

			cout << setw(3) << iter->first << "." << iter->second << endl;
		}
	}

	return 0;
}