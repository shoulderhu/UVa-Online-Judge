#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, S, x, y;
	char orientation, arena[100][100];
	string line, instruction;

	while (cin >> N >> M >> S && !(N == 0 && M == 0 && S == 0)) {

		int collect = 0;

		for (int i = 0; i < N; ++i) {

			cin >> line;

			for (int j = 0; j < M; ++j) { 
				
				arena[i][j] = line[j]; 

				if (isalpha(line[j]) != 0) {
					
					orientation = line[j], x = i, y = j;
				}
			}
		}
				
		cin >> instruction;

		for (int i = 0; i < instruction.size(); ++i) {

			if (instruction[i] == 'D') {

				switch (orientation) {

				case 'N': orientation = 'L'; break;
				case 'S': orientation = 'O'; break;
				case 'L': orientation = 'S'; break;
				case 'O': orientation = 'N'; break;
				}
			}
			else if (instruction[i] == 'E') {

				switch (orientation) {

				case 'N': orientation = 'O'; break;
				case 'S': orientation = 'L'; break;
				case 'L': orientation = 'N'; break;
				case 'O': orientation = 'S'; break;
				}
			}
			else {

				int X = x, Y = y;

				switch (orientation) {

				case 'N': X -= 1; break;
				case 'S': X += 1; break;
				case 'L': Y += 1; break;
				case 'O': Y -= 1; break;
				}

				if (X >= 0 && Y >= 0 && X < N && Y < M && arena[X][Y] != '#') {

					if (arena[X][Y] == '*') { ++collect, arena[X][Y] = '.'; }
					x = X, y = Y;
				}
			}
		}

		cout << collect << endl;
	}

	return 0;
}