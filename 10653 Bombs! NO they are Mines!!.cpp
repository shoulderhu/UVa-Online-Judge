#include <iostream>
#include <queue>

using namespace std;

bool map[1000][1000], isVisit[1000][1000];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int R, C, rows, row, column, bomb;	
	struct xy { int x, y; }S, D;

	while (cin >> R >> C && !(R == 0 && C == 0)) {

		for (int i = 0; i < R; ++i) {

			for (int j = 0; j < C; ++j) {

				map[i][j] = true;
				isVisit[i][j] = false;
			}
		}
		
		cin >> rows;

		for (int i = 1; i <= rows; ++i) {

			cin >> row >> bomb;

			for (int j = 1; j <= bomb; ++j) {

				cin >> column;
				map[row][column] = false;
			}
		}

		cin >> S.x >> S.y >> D.x >> D.y;

		queue<struct xy> Queue;
		Queue.push(S), isVisit[S.x][S.y] = true;

		for (int i = 0; ; ++i) {

			int length = Queue.size();
			bool isFound = false;

			for (int j = 1; j <= length; ++j) {

				struct xy l = Queue.front();
				
				if (l.x == D.x && l.y == D.y) { 
					
					cout << i << endl; 
					isFound = true; break;
				}
				else {

					struct xy temp;
					Queue.pop();

					if (l.x + 1 < R && map[l.x + 1][l.y] == true && isVisit[l.x + 1][l.y] == false) {

						temp.x = l.x + 1, temp.y = l.y, Queue.push(temp), isVisit[l.x + 1][l.y] = true;
					}
					if (l.x - 1 >= 0 && map[l.x - 1][l.y] == true && isVisit[l.x - 1][l.y] == false) {

						temp.x = l.x - 1, temp.y = l.y, Queue.push(temp), isVisit[l.x - 1][l.y] = true;
					}
					if (l.y + 1 < C && map[l.x][l.y + 1] == true && isVisit[l.x][l.y + 1] == false) {

						temp.x = l.x, temp.y = l.y + 1, Queue.push(temp), isVisit[l.x][l.y + 1] = true;
					}
					if (l.y - 1 >= 0 && map[l.x][l.y - 1] == true && isVisit[l.x][l.y - 1] == false) {

						temp.x = l.x, temp.y = l.y - 1, Queue.push(temp), isVisit[l.x][l.y - 1] = true;
					}
				}				
			}

			if (isFound == true) { break; }
		}
	}

	return 0;
}