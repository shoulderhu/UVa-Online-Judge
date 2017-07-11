#include <iostream>
#include <algorithm>

using namespace std;

int n, m, Array[1000000], range;

struct road { 
	
	int from, to, length;

	bool operator<(struct road &r) {

		return length < r.length;
	}
}Road[1000000];

inline int getRoot(int &r) {

	if (Array[r] == r) { return r; }
	else { return Array[r] = getRoot(Array[r]); }
}

int main() {

	ios::sync_with_stdio(false);	

	while (cin >> n >> m && !(n == 0 && m == 0)) {

		int N = 0;

		for (int i = 0; i < n; ++i) { Array[i] = i; }

		for (int i = 0; i < m; ++i) {

			cin >> Road[i].from >> Road[i].to >> Road[i].length;
		}

		sort(Road, Road + m);

		for (int i = 0; i < m && N < n; ++i) {

			Road[i].from = getRoot(Road[i].from);
			Road[i].to = getRoot(Road[i].to);

			if (Road[i].from != Road[i].to) {

				range = Road[i].length, ++N;
				Array[Road[i].to] = Road[i].from;
			}
		}

		if (N == n - 1) { cout << range << endl; }
		else { cout << "IMPOSSIBLE" << endl; }
	}

	return 0;
}