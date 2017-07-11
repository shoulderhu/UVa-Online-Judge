#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

inline bool mySort(pair<char, int>& a, pair<char, int>& b) { return a.second > b.second; }

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int X, R, C, M, N;
	char image[20][20];

	cin >> X;

	for (int i = 1; i <= X; ++i) {

		cin >> R >> C >> M >> N;

		map<char, int> Map;

		for (int j = 0; j < R; ++j) {

			for (int k = 0; k < C; ++k) {

				cin >> image[j][k];
				++Map[image[j][k]];
			}
		}

		int maxRegion = 1;
		vector<pair<char, int>> Vector(Map.begin(), Map.end());
		sort(Vector.begin(), Vector.end(), mySort);
				
		for (int j = 1; j < Vector.size(); ++j) {

			if (Vector[j].second == Vector[0].second) { ++maxRegion; }
			else { break; }
		}

		int important = maxRegion * Vector[0].second, normal = R*C - important;
		
		cout << "Case " << i << ": " << important * M + normal * N << endl;
	}

	return 0;
}