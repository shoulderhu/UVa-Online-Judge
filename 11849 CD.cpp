#include <iostream>
#include <set>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, n, m;

	while (cin >> N >> M && !(N == 0 && M == 0)) {

		int CD = 0;
		set<int> Jack;

		for (int i = 1; i <= N; ++i) {

			cin >> n;
			Jack.insert(n);
		}

		for (int i = 1; i <= M; ++i) {

			cin >> m;
			if (Jack.find(m) != Jack.end()) { ++CD; }
		}

		cout << CD << endl;
	}
	
	return 0;
}