#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int X, N, M, L, A, B, cost, n, a;
	string line, name;
	stringstream ss;
	pair<string, int> agency[100];
	
	cin >> X;

	for (int i = 1; i <= X; ++i) {

		cin >> N >> M >> L;
		a = -1;

		for (int j = 0; j < L; ++j) {

			cin >> line;
			line[line.find(':')] = ' ';
			line[line.find(',')] = ' ';
			ss.clear(), ss << line, ss >> name >> A >> B;
			n = N, cost = 0;

			while (A > B / ceil(n / 2.0) && n / 2 >= M) {

				cost += B;
				n /= 2;
			}

			cost += A * (n - M);
			agency[++a] = make_pair(name, cost);
		}

		sort(agency, agency + a + 1, [](pair<string, int> &a, pair<string, int> &b) {
			
			if (a.second != b.second) { return a.second < b.second; }
			else { return a.first < b.first; }
		});

		cout << "Case " << i << '\n';

		for (int j = 0; j <= a; ++j) {

			cout << agency[j].first << " " << agency[j].second << "\n";
		}
	}

	return 0;
}
