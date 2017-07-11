#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int game, n, solution[10][10];
	char grid[10][10], touch[10][10];
	string line;

	cin >> game;

	for (int i = 1; i <= game; ++i) {

		if (i > 1) { cout << endl; }

		cin >> n;

		for (int j = 0; j < n; ++j) {

			cin >> line;
			for (int k = 0; k < n; ++k) { grid[j][k] = line[k]; }
		}

		for (int j = 0; j < n; ++j) {

			for (int k = 0; k < n; ++k) {

				cin >> touch[j][k];
				solution[j][k] = 0;
			}
		}

		for (int j = 0; j < n; ++j) {

			for (int k = 0; k < n; ++k) {

				if (grid[j][k] == '*') {
					
					if (j - 1 >= 0 && k - 1 >= 0 && touch[j - 1][k - 1] == 'x') { 
						
						++solution[j - 1][k - 1];
					}
					if (j - 1 >= 0 && touch[j - 1][k] == 'x') { ++solution[j - 1][k]; }
					if (j - 1 >= 0 && k + 1 < n && touch[j - 1][k + 1] == 'x') {
						
						++solution[j - 1][k + 1];
					}
					if (k - 1 >= 0 && touch[j][k - 1] == 'x') { ++solution[j][k - 1]; }
					if (k + 1 < n && touch[j][k + 1] == 'x') { ++solution[j][k + 1]; }
					if (j + 1 < n && k - 1 >= 0 && touch[j + 1][k - 1] == 'x') {
						
						++solution[j + 1][k - 1]; 
					}
					if (j + 1 < n && touch[j + 1][k] == 'x') { ++solution[j + 1][k]; }
					if (j + 1 < n && k + 1 < n && touch[j + 1][k + 1] == 'x') { 
						
						++solution[j + 1][k + 1]; 
					}
				}
			}
		}

		bool isLose = false;

		for (int j = 0; j < n && isLose == false; ++j) {

			for (int k = 0; k < n; ++k) {

				if (touch[j][k] == 'x' && grid[j][k] == '*') {
				
					for (int l = 0; l < n; ++l, cout << endl) {

						for (int m = 0; m < n; ++m) {

							if (grid[l][m] == '*') { cout << "*"; }
							else if (touch[l][m] == 'x') { cout << solution[l][m]; }
							else { cout << "."; }
						}
					}

					isLose = true; break;
				}
			}
		}

		if (isLose == false) {

			for (int l = 0; l < n; ++l, cout << endl) {

				for (int m = 0; m < n; ++m) {
										
					if (touch[l][m] == 'x') { cout << solution[l][m]; }
					else { cout << "."; }
				}
			}
		}
	}

	return 0;
}