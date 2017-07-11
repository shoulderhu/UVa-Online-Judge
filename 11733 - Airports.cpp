#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M, A;
struct road { int X, Y, C; };
vector<int> Vec;

inline int getRoot(int r) {

	if (Vec[r] == r) { return r; }
	else { return Vec[r] = getRoot(Vec[r]); }
}

int main() {

	ios::sync_with_stdio(false);

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> N >> M >> A;

		int n = 0, Y = 0, Z = 0;
		vector<struct road> Road(M);

		Vec.clear();
		for (int j = 0; j <= N; ++j) { Vec.push_back(j); }

		for (int j = 0; j < M; ++j) {

			cin >> Road[j].X >> Road[j].Y >> Road[j].C;
		}

		sort(Road.begin(), Road.end(), [](struct road &a, struct road &b) {

			return a.C < b.C;
		});

		for (int j = 0; j < M && n < N; ++j) {

			Road[j].X = getRoot(Road[j].X);
			Road[j].Y = getRoot(Road[j].Y);

			if (Road[j].X != Road[j].Y) {

				++n, Vec[Road[j].Y] = Road[j].X;
				if (Road[j].C >= A) { ++Z, Y += A; }
				else { Y += Road[j].C; }
			}
		}

		for (int j = 1; j <= N; ++j) {

			if (Vec[j] == j) { ++Z, Y += A; }
		}

		cout << "Case #" << i << ": " << Y << " " << Z << endl;
	}

	return 0;
}