#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int emptyX, emptyY, puzzle = 0;
	char Puzzle[5][5];
	string line;

	while (getline(cin, line) && line != "Z") {

		if (puzzle > 0) { cout << endl; }

		bool hasFinal = true;
		string move;

		if (line.size() == 4) { line += " "; }

		for (int i = 0; i < 5; ++i) { 
			
			Puzzle[0][i] = line[i];
			if (Puzzle[0][i] == ' ') { emptyX = 0, emptyY = i; }
		}
		
		for (int i = 1; i < 5; ++i) {

			getline(cin, line);

			if (line.size() == 4) { line += " "; }

			for (int j = 0; j < line.size(); ++j) { 
				
				Puzzle[i][j] = line[j]; 				
				if (Puzzle[i][j] == ' ') { emptyX = i, emptyY = j; }
			}			
		}

		while (cin >> line) {

			cin.ignore(), move += line;
			if (line.back() == '0') { break; }
		}
		
		for (int i = 0; i < move.size() - 1; ++i) {

			if (move[i] == 'A') {

				if (emptyX - 1 < 0) { hasFinal = false;	break; }
				else { 
					
					swap(Puzzle[emptyX][emptyY], Puzzle[emptyX - 1][emptyY]);
					--emptyX;
				}
			}
			else if (move[i] == 'B') {

				if (emptyX + 1 > 4) { hasFinal = false;	break; }
				else { 
					
					swap(Puzzle[emptyX][emptyY], Puzzle[emptyX + 1][emptyY]);
					++emptyX;
				}
			}
			else if (move[i] == 'R') {

				if (emptyY + 1 > 4) { hasFinal = false;	break; }
				else { 
					
					swap(Puzzle[emptyX][emptyY], Puzzle[emptyX][emptyY + 1]);
					++emptyY;
				}
			}
			else {

				if (emptyY - 1 < 0) { hasFinal = false;	break; }
				else { 
					
					swap(Puzzle[emptyX][emptyY], Puzzle[emptyX][emptyY - 1]);
					--emptyY;
				}
			}
		}

		cout << "Puzzle #" << ++puzzle << ":" << endl;

		if (hasFinal == false) { 
			
			cout << "This puzzle has no final configuration." << endl;
		}
		else {

			for (int i = 0; i < 5; ++i, cout << endl) {

				cout << Puzzle[i][0];

				for (int j = 1; j < 5; ++j) {

					cout << " " << Puzzle[i][j];
				}
			}
		}		
	}

	return 0;
}