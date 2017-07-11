#include <iostream>
#include <deque>

using namespace std;

int T, M, N, Size, L;
char chess[100][100];
bool isReach;
pair<int, int> p, B;
deque<pair<int, int>> A, Z;

int main() {

	ios::sync_with_stdio(false);

	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> M >> N;
		A.clear(), Z.clear();

		for (int j = 0; j < M; ++j) {

			for (int k = 0; k < N; ++k) {

				cin >> chess[j][k];
				
				switch (chess[j][k]) {

				case 'A': A.push_back({ j, k }); break;
				case 'B': B.first = j, B.second = k; break;
				case 'Z': Z.push_back({ j, k }); break;
				}				
			}
		}

		for (int j = 0; j < Z.size(); ++j) {
			
			if (Z[j].first - 1 >= 0 && Z[j].second - 2 >= 0 &&
				chess[Z[j].first - 1][Z[j].second - 2] == '.') {

				chess[Z[j].first - 1][Z[j].second - 2] = 'Z';
			}
			if (Z[j].first - 2 >= 0 && Z[j].second - 1 >= 0 &&
				chess[Z[j].first - 2][Z[j].second - 1] == '.') {

				chess[Z[j].first - 2][Z[j].second - 1] = 'Z';
			}
			if (Z[j].first - 2 >= 0 && Z[j].second + 1 < N &&
				chess[Z[j].first - 2][Z[j].second + 1] == '.') {

				chess[Z[j].first - 2][Z[j].second + 1] = 'Z';
			}
			if (Z[j].first - 1 >= 0 && Z[j].second + 2 < N &&
				chess[Z[j].first - 1][Z[j].second + 2] == '.') {

				chess[Z[j].first - 1][Z[j].second + 2] = 'Z';
			}
			if (Z[j].first + 1 < M && Z[j].second + 2 < N &&
				chess[Z[j].first + 1][Z[j].second + 2] == '.') {

				chess[Z[j].first + 1][Z[j].second + 2] = 'Z';
			}
			if (Z[j].first + 2 < M && Z[j].second + 1 < N &&
				chess[Z[j].first + 2][Z[j].second + 1] == '.') {

				chess[Z[j].first + 2][Z[j].second + 1] = 'Z';
			}
			if (Z[j].first + 2 < M && Z[j].second - 1 >= 0 &&
				chess[Z[j].first + 2][Z[j].second - 1] == '.') {

				chess[Z[j].first + 2][Z[j].second - 1] = 'Z';
			}
			if (Z[j].first + 1 < M && Z[j].second - 2 >= 0 &&
				chess[Z[j].first + 1][Z[j].second - 2] == '.') {

				chess[Z[j].first + 1][Z[j].second - 2] = 'Z';
			}
		}

		L = -1, isReach = false, chess[B.first][B.second] = '.';

		while (!A.empty()) {

			Size = A.size(), ++L;

			for (int j = 0; j < Size; ++j) {

				p = A.front(), A.pop_front();

				if (p == B) { isReach = true; break; }

				if (p.first - 1 >= 0 && p.second - 1 >= 0 &&
					chess[p.first - 1][p.second - 1] == '.') {

					chess[p.first - 1][p.second - 1] = 'A';
					A.push_back({p.first - 1, p.second - 1});
				}
				if (p.first - 1 >= 0 &&
					chess[p.first - 1][p.second] == '.') {

					chess[p.first - 1][p.second] = 'A';
					A.push_back({ p.first - 1, p.second });
				}
				if (p.first - 1 >= 0 && p.second + 1 < N &&
					chess[p.first - 1][p.second + 1] == '.') {

					chess[p.first - 1][p.second + 1] = 'A';
					A.push_back({ p.first - 1, p.second + 1 });
				}
				if (p.second - 1 >= 0 &&
					chess[p.first][p.second - 1] == '.') {

					chess[p.first][p.second - 1] = 'A';
					A.push_back({ p.first, p.second - 1 });
				}
				if (p.second + 1 < N &&
					chess[p.first][p.second + 1] == '.') {

					chess[p.first][p.second + 1] = 'A';
					A.push_back({ p.first, p.second + 1 });
				}
				if (p.first + 1 < M && p.second - 1 >= 0 &&
					chess[p.first + 1][p.second - 1] == '.') {

					chess[p.first + 1][p.second - 1] = 'A';
					A.push_back({ p.first + 1, p.second - 1 });
				}
				if (p.first + 1 < M && 
					chess[p.first + 1][p.second] == '.') {

					chess[p.first + 1][p.second] = 'A';
					A.push_back({ p.first + 1, p.second });
				}
				if (p.first + 1 < M && p.second + 1 < N &&
					chess[p.first + 1][p.second + 1] == '.') {

					chess[p.first + 1][p.second + 1] = 'A';
					A.push_back({ p.first + 1, p.second + 1 });
				}
			}

			if (isReach) { break; }
		}

		if(!isReach){ cout << "King Peter, you can't go now!" << endl; }
		else{ cout << "Minimal possible length of a trip is " << L << endl; }		
	}

	return 0;
}