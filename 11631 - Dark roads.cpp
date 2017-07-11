#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<int> Vec;

inline int getRoot(int r) {

	if (Vec[r] == r) { return r; }
	else { return Vec[r] = getRoot(Vec[r]); }
}

int main() {

	ios::sync_with_stdio(false);
	
	while (cin >> m >> n && !(m == 0 && n == 0)) {
		
		int money = 0, M = 0;
		vector<tuple<int, int, int>> road(n);
		
		Vec.clear();
		for (int i = 0; i < m; ++i) { Vec.push_back(i); }

		for (int i = 0; i < n; ++i) {

			cin >> get<0>(road[i]) >> get<1>(road[i]) >> get<2>(road[i]);
			money += get<2>(road[i]);
		}

		sort(road.begin(), road.end(), 
			 [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
		
			return get<2>(a) < get<2>(b);
		});

		for (int i = 0; i < n && M < m; ++i) {

			get<0>(road[i]) = getRoot(get<0>(road[i]));
			get<1>(road[i]) = getRoot(get<1>(road[i]));

			if (get<0>(road[i]) != get<1>(road[i])) {

				money -= get<2>(road[i]), ++M;
				Vec[get<1>(road[i])] = get<0>(road[i]);
			}
		}

		cout << money << endl;
	}

	return 0;
}