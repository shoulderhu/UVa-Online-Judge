#include <iostream>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int Case = 0, M, N, Size, Time;
char grid[25][25];
bool isReach, isVisit[25][25][4][5];
tuple<int, int, int, int> S;
queue<tuple<int, int, int, int>> Queue;

inline int getColor(int &c) {

	switch (c) {

	case 0: return 1; break;
	case 1: return 2; break;
	case 2: return 3; break;
	case 3: return 4; break;
	case 4: return 0; break;
	}
}

int main() {

	while (cin >> M >> N && !(M == 0 && N == 0)) {

		if (Case > 0) { cout << endl; }

		while (!Queue.empty()) { Queue.pop(); }

		for (int i = 0; i < M; ++i) {

			for (int j = 0; j < N; ++j) {

				cin >> grid[i][j];
			
				for (int k = 0; k < 4; ++k) {
					
					for (int l = 0; l < 5; ++l) {

						isVisit[i][j][k][l] = false;
					}				
				}

				if (grid[i][j] == 'S') {

					isVisit[i][j][0][0] = true;
					Queue.push({ i, j, 0, 0 });
				}				
			}
		}

		isReach = false, Time = 0;

		while (!Queue.empty()) {

			Size = Queue.size(), ++Time;

			for (int i = 0; i < Size; ++i) {

				S = Queue.front(), Queue.pop();

				if (get<3>(S) == 0 &&
					grid[get<0>(S)][get<1>(S)] == 'T') {

					isReach = true; break;
				}

				switch (get<2>(S)) {

				case 0:

					if (!isVisit[get<0>(S)][get<1>(S)][3][get<3>(S)]) {

						isVisit[get<0>(S)][get<1>(S)][3][get<3>(S)] = true;
						get<2>(S) = 3, Queue.push(S);
					}

					if (!isVisit[get<0>(S)][get<1>(S)][1][get<3>(S)]) {

						isVisit[get<0>(S)][get<1>(S)][1][get<3>(S)] = true;
						get<2>(S) = 1, Queue.push(S);
					}				

					if (get<0>(S) - 1 >= 0 &&
						grid[get<0>(S) - 1][get<1>(S)] != '#' &&
						!isVisit[get<0>(S) - 1][get<1>(S)][0][getColor(get<3>(S))]) {

						isVisit[get<0>(S) - 1][get<1>(S)][0][getColor(get<3>(S))] = true;
						Queue.push({ get<0>(S) - 1, get<1>(S), 0, getColor(get<3>(S)) });
					}				
					break;
				case 1:

					if (!isVisit[get<0>(S)][get<1>(S)][0][get<3>(S)]) {

						isVisit[get<0>(S)][get<1>(S)][0][get<3>(S)] = true;
						get<2>(S) = 0, Queue.push(S);
					}

					if (!isVisit[get<0>(S)][get<1>(S)][2][get<3>(S)]) {

						isVisit[get<0>(S)][get<1>(S)][2][get<3>(S)] = true;
						get<2>(S) = 2, Queue.push(S);
					}
					
					if (get<1>(S) + 1 < N &&
						grid[get<0>(S)][get<1>(S) + 1] != '#' &&
						!isVisit[get<0>(S)][get<1>(S) + 1][1][getColor(get<3>(S))]) {

						isVisit[get<0>(S)][get<1>(S) + 1][1][getColor(get<3>(S))] = true;
						Queue.push({ get<0>(S), get<1>(S) + 1, 1, getColor(get<3>(S)) });
					}					
					break;
				case 2:

					if (!isVisit[get<0>(S)][get<1>(S)][1][get<3>(S)]) {

						isVisit[get<0>(S)][get<1>(S)][1][get<3>(S)] = true;
						get<2>(S) = 1, Queue.push(S);
					}

					if (!isVisit[get<0>(S)][get<1>(S)][3][get<3>(S)]) {

						isVisit[get<0>(S)][get<1>(S)][3][get<3>(S)] = true;
						get<2>(S) = 3, Queue.push(S);
					}
					
					if (get<0>(S) + 1 < M &&
						grid[get<0>(S) + 1][get<1>(S)] != '#' &&
						!isVisit[get<0>(S) + 1][get<1>(S)][2][getColor(get<3>(S))]) {

						isVisit[get<0>(S) + 1][get<1>(S)][2][getColor(get<3>(S))] = true;
						Queue.push({ get<0>(S) + 1, get<1>(S), 2, getColor(get<3>(S)) });
					}					
					break;
				case 3:

					if (!isVisit[get<0>(S)][get<1>(S)][2][get<3>(S)]) {

						isVisit[get<0>(S)][get<1>(S)][2][get<3>(S)] = true;
						get<2>(S) = 2, Queue.push(S);
					}

					if (!isVisit[get<0>(S)][get<1>(S)][0][get<3>(S)]) {

						isVisit[get<0>(S)][get<1>(S)][0][get<3>(S)] = true;
						get<2>(S) = 0, Queue.push(S);
					}
					
					if (get<1>(S) - 1 >= 0 &&
						grid[get<0>(S)][get<1>(S) - 1] != '#' &&
						!isVisit[get<0>(S)][get<1>(S) - 1][3][getColor(get<3>(S))]) {

						isVisit[get<0>(S)][get<1>(S) - 1][3][getColor(get<3>(S))] = true;
						Queue.push({ get<0>(S), get<1>(S) - 1, 3, getColor(get<3>(S)) });
					}					
					break;
				}				
			}

			if (isReach) { break; }
		}

		cout << "Case #" << ++Case << endl;	
		if (!isReach) { cout << "destination not reachable" << endl; }
		else { cout << "minimum time = " << Time - 1 << " sec" << endl; }
	}

	return 0;
}