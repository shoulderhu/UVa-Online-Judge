#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int M, N;
char same, C, table[251][251];
bool isVisit[251][251];

void DFS(int Y, int X) {

	if (Y < 1 || X < 1 || Y > N || X > M || isVisit[Y][X] == true || 
		                                    table[Y][X] != same) { return; }
	else {

		isVisit[Y][X] = true;
		table[Y][X] = C;
		DFS(Y - 1, X);
		DFS(Y, X + 1);
		DFS(Y + 1, X);
		DFS(Y, X - 1);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int X[2], Y[2];
	char command;
	string Name;

	while (cin >> command && command != 'X') {

		if (command == 'I') {

			cin >> M >> N;

			for (int i = 1; i <= N; ++i) {

				for (int j = 1; j <= M; ++j) {

					table[i][j] = 'O';
				}
			}			
		}
		else if (command == 'C') {

			for (int i = 1; i <= N; ++i) {

				for (int j = 1; j <= M; ++j) {

					table[i][j] = 'O';
				}
			}
		}
		else if (command == 'L') {

			cin >> X[0] >> Y[0] >> C;
			table[Y[0]][X[0]] = C;
		}
		else if (command == 'V') {

			cin >> X[0] >> Y[0] >> Y[1] >> C;

			sort(Y, Y + 2);
			for (int i = Y[0]; i <= Y[1]; ++i) { table[i][X[0]] = C; }
		}
		else if (command == 'H') {

			cin >> X[0] >> X[1] >> Y[0] >> C;

			sort(X, X + 2);
			for (int i = X[0]; i <= X[1]; ++i) { table[Y[0]][i] = C; }
		}
		else if (command == 'K') {

			cin >> X[0] >> Y[0] >> X[1] >> Y[1] >> C;

			sort(X, X + 2), sort(Y, Y + 2);

			for (int i = Y[0]; i <= Y[1]; ++i) { 
			
				for (int j = X[0]; j <= X[1]; ++j) {

					table[i][j] = C;
				}
			}
		}
		else if (command == 'F') {

			cin >> X[0] >> Y[0] >> C;
						
			for (int i = 1; i <= N; ++i) {

				for (int j = 1; j <= M; ++j) {

					isVisit[i][j] = false;
				}
			}

			same = table[Y[0]][X[0]], DFS(Y[0], X[0]);		
		}
		else if (command == 'S') {
						
			cin >> Name;
			cout << Name << endl;

			for (int i = 1; i <= N; ++i) {

				for (int j = 1; j <= M; ++j) {

					cout << table[i][j];
				}

				cout << endl;
			}
		}		
	}

	return 0;
}