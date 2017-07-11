#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T, N;

	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> N;

		vector<pair<int, int>> dot(N);

		for (int i = 0; i < N; ++i) {

			cin >> dot[i].first >> dot[i].second;
		}

		sort(dot.begin(), dot.end(), [](pair<int, int> &a, pair<int, int> &b) {

			return a.first < b.first;
		});

		bool isSymmetric = true;
		double X = (dot.front().first + dot.back().first) / 2.0;
		
		for (int i = 0; i < N; ++i) {

			bool isFind = false;

			for (int j = N - 1; j >= 0; --j) {

				if (dot[i].second == dot[j].second && 
					(dot[i].first == X || (dot[i].first + dot[j].first) / 2.0 == X)) {

					isFind = true; break;
				}
			}

			if (!isFind) { isSymmetric = false; break; }
		}

		cout << (isSymmetric ? "YES" : "NO") << endl;
	}

	return 0;
}