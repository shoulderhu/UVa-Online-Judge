#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> Vec;

inline int getRoot(int e) {

	if (Vec[e] == e) { return e; }
	else { return Vec[e] = getRoot(Vec[e]); }
}

int main() {
	
	ios::sync_with_stdio(false);

	while (cin >> n >> m && !(n == 0 && m == 0)) {
				
		vector<tuple<int, int, int>> edge(m);

		Vec.clear();
		for (int i = 0; i < n; ++i) { Vec.push_back(i); }

		for (int i = 0; i < m; ++i) {

			cin >> get<0>(edge[i]) >> get<1>(edge[i]) >> get<2>(edge[i]);
		}

		sort(edge.begin(), edge.end(), 
			 [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
		
			return get<2>(a) < get<2>(b);
		});

		bool isFirst = true;			
			
		for (int i = 0; i < m; ++i) {

			get<0>(edge[i]) = getRoot(get<0>(edge[i]));
			get<1>(edge[i]) = getRoot(get<1>(edge[i]));

			if (get<0>(edge[i]) != get<1>(edge[i])) {

				Vec[get<1>(edge[i])] = get<0>(edge[i]);
			}
			else {
				
				if (!isFirst) { cout << " "; }
				else { isFirst = false; }
				cout << get<2>(edge[i]);
			}
		}
		
		if (isFirst) { cout << "forest"; }
		cout << endl;
	}

	return 0;
}