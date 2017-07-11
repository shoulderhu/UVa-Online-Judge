#include <iostream>
#include <iomanip>

using namespace std;

int Row[8], dataset, row, column, solution = 0, set = 0, All[92][8];

void Queen(int step) {

	if (step < 8) {

		for (int i = 0; i < 8; ++i) {

			for (int j = 0; j < step; ++j) {

				if (Row[j] == i || Row[j] - i == j - step || 
					Row[j] - i == step - j) { break; }
				
				if (j == step - 1) {

					Row[step] = i;
					Queen(step + 1);
				}
			}			
		}
	}
	else {
		
		for (int i = 0; i < 8; ++i) {

			All[set][i] = Row[i] + 1;
		}

		++set;		
	}
}

int main() {

	ios::sync_with_stdio(false);
	
	for (int i = 0; i < 8; ++i) {

		Row[0] = i;
		Queen(1);
	}

	cin >> dataset;

	for (int i = 0; i < dataset; ++i) {
		
		if (i > 0) { 
			
			cout << endl;
			solution = 0;
		}
				
		cin >> row >> column;		
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl;
		cout << endl;
						
		for (int i = 0; i < 92; ++i) {

			if (All[i][column - 1] == row) {

				cout << setw(2) << ++solution << "     ";

				for (int j = 0; j < 8; ++j) {
					
					cout << " " << All[i][j];
				}

				cout << endl;
			}
		}
	}
	
	return 0;
}