#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace, maze[61][61], row, column, x, y;
	string line;

	cin >> kace;

	for (int i = 1; i <= kace; ++i) {

		if (i > 1) { cout << endl; }

		cin >> row >> column, cin.ignore(1024, '\n');

		for (int j = 1; j <= row; ++j) {

			getline(cin, line);
			for (int k = 1; k <= column; ++k) { maze[j][k] = line[k - 1]; }
		}

		cin >> x >> y;

		char orientation = 'N';
		bool isQ = false;

		while (cin >> line) {

			for (int j = 0; j < line.size(); ++j) {

				if (line[j] == 'R') {
				
					switch (orientation) {

					case 'N': orientation = 'E'; break;
					case 'W': orientation = 'N'; break;
					case 'S': orientation = 'W'; break;
					case 'E': orientation = 'S'; break;
					}
				}
				else if (line[j] == 'L') {
				
					switch (orientation) {

					case 'N': orientation = 'W'; break;
					case 'W': orientation = 'S'; break;
					case 'S': orientation = 'E'; break;
					case 'E': orientation = 'N'; break;
					}
				}
				else if (line[j] == 'F') {
					
					int X = x, Y = y;

					switch (orientation) {

					case 'N': X -= 1; break;
					case 'W': Y -= 1; break;
					case 'S': X += 1; break;
					case 'E': Y += 1; break;
					}

					if (X > 0 && Y > 0 && X < row && Y < column && maze[X][Y]==' ') {
						 
						x = X, y = Y;
					}
				}
				else { 
				
					cout << x << " " << y << " " << orientation << endl;
					isQ = true;	break;
				}
			}

			if (isQ == true) { break; }
		}
	}

	return 0;
}