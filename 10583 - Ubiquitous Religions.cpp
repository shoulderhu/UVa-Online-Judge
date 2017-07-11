#include <iostream>

using namespace std;

int Array[50001];

inline int getRoot(int v) {

	if (Array[v] == v) { return v; }
	else { return Array[v] = getRoot(Array[v]); }
}

int main() {

	int n, m, i, j, cases = 0;

	while (cin >> n >> m && !(n == 0 && m == 0)) {

		for (int k = 1; k <= n; ++k) { Array[k] = k; }

		for (int k = 0; k < m; ++k) {

			cin >> i >> j;
			i = getRoot(i), j = getRoot(j);
			Array[j] = i;
		}

		int religion = 0;

		for (int k = 1; k <= n; ++k) {

			if (Array[k] == k) { ++religion; }
		}

		cout << "Case " << ++cases << ": " << religion << endl;
	}

	return 0;
}
