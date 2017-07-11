#include <iostream>
#include <queue>

using namespace std;

bool isVisit[30][30][30];
char Dungeon[30][30][30];
struct pos { int x, y, z; }S, E, P, p;

inline bool isE(struct pos &p) { return E.x == p.x && E.y == p.y && E.z == p.z; }

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int L, R, C;	
	
	while (cin >> L >> R >> C && L != 0 || R != 0 || C != 0) {

		for (int i = 0; i < L; ++i) {

			for (int j = 0; j < R; ++j) {

				for (int k = 0; k < C; ++k) {

					cin >> Dungeon[i][j][k];
					isVisit[i][j][k] = false;

					switch (Dungeon[i][j][k]) {

					case 'S': S.x = i, S.y = j, S.z = k; break;
					case 'E': E.x = i, E.y = j, E.z = k; break;
					}					
				}
			}
		}

		bool isEnd = false;
		queue<struct pos> Queue;
		Queue.push(S), isVisit[S.x][S.y][S.z] = true;

		for (int i = 1; !Queue.empty(); ++i) {

			int Size = Queue.size();

			for (int j = 0; j < Size; ++j) {

				P = Queue.front(), Queue.pop();

				if (P.y - 1 > -1 && Dungeon[P.x][P.y - 1][P.z] != '#' && !isVisit[P.x][P.y - 1][P.z]) {

					p = P, --p.y, Queue.push(p), isVisit[p.x][p.y][p.z] = true;
					if (isE(p)) { isEnd = true; break; }
				}
				if (P.y + 1 < R && Dungeon[P.x][P.y + 1][P.z] != '#' && !isVisit[P.x][P.y + 1][P.z]) {
				
					p = P, ++p.y, Queue.push(p), isVisit[p.x][p.y][p.z] = true;
					if (isE(p)) { isEnd = true; break; }
				}
				if (P.z + 1 < C && Dungeon[P.x][P.y][P.z + 1] != '#' && !isVisit[P.x][P.y][P.z + 1]) {
				
					p = P, ++p.z, Queue.push(p), isVisit[p.x][p.y][p.z] = true;
					if (isE(p)) { isEnd = true; break; }
				}
				if (P.z - 1 > -1 && Dungeon[P.x][P.y][P.z - 1] != '#' && !isVisit[P.x][P.y][P.z - 1]) {
				
					p = P, --p.z, Queue.push(p), isVisit[p.x][p.y][p.z] = true;	
					if (isE(p)) { isEnd = true; break; }
				}
				if (P.x - 1 > -1 && Dungeon[P.x - 1][P.y][P.z] != '#' && !isVisit[P.x - 1][P.y][P.z]) {
					
					p = P, --p.x, Queue.push(p), isVisit[p.x][p.y][p.z] = true;
					if (isE(p)) { isEnd = true; break; }
				}
				if (P.x + 1 < L && Dungeon[P.x + 1][P.y][P.z] != '#' && !isVisit[P.x + 1][P.y][P.z]) {
				
					p = P, ++p.x, Queue.push(p), isVisit[p.x][p.y][p.z] = true;
					if (isE(p)) { isEnd = true; break; }
				}
			}

			if (isEnd) { cout << "Escaped in " << i << " minute(s)." << endl; break; }
		}

		if (!isEnd) { cout << "Trapped!" << endl; }
	}

	return 0;
}