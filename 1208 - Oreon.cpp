#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Array[26];

inline int getRoot(int v) {

	if (Array[v] == v) { return v; }
	else { return Array[v] = getRoot(Array[v]); }
}

int main() {
		
	cin.tie(0);

	int Case, city, x, y, f, t;	
	struct edge { int from, to, person; }e;
	vector<struct edge> Edge;

	cin >> Case;

	for (int i = 1; i <= Case; ++i) {

		cin >> city;
		Edge.clear();

		for (int j = 0; j < city; ++j) {

			Array[j] = j;

			for (int k = 0; k < city; ++k) {

				if (k + 1 != city) {

					scanf("%d,", &e.person);
				}
				else { scanf("%d", &e.person); }
				
				if (j < k && e.person != 0) {

					e.from = j, e.to = k;
					Edge.push_back(e);
				}
			}
		}

		sort(Edge.begin(), Edge.end(), [](struct edge &a, struct edge &b) {

			if (a.person != b.person) { return a.person < b.person; }
			else if (a.from != b.from) { return a.from < b.from; }
			else { return a.to < b.to; }
		});

		cout << "Case " << i << ":\n";

		for (int j = 0; j < Edge.size(); ++j) {

			f = Edge[j].from, t = Edge[j].to;

			if ((x = getRoot(f)) != (y = getRoot(t))) {

				Array[y] = x;
				cout << (char)(f + 65) << '-' << (char)(t + 65) << ' ' << Edge[j].person << '\n';
			}
		}
	}

	return 0;
}