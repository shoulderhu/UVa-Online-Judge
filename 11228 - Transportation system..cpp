#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int city[1000];
struct node { int x, y; }N[1000];

struct edge { 
	
	int x, y;
	double w;
	
	bool operator<(struct edge &e) {

		return w < e.w;
	}
}E[499500];

inline int getRoot(int e) {

	if (city[e] == e) { return e; }
	else { return city[e] = getRoot(city[e]); }
}

int main() {

	ios::sync_with_stdio(false);

	int T, n, r;

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> n >> r;
		
		for (int j = 0; j < n; ++j) { 
						
			city[j] = j;
			cin >> N[j].x >> N[j].y;
		}

		int l = 0, state = 1;
		double road = 0, rail = 0;

		for (int j = 0; j < n; ++j) {

			for (int k = j + 1; k < n; ++k, ++l) {

				E[l].x = j, E[l].y = k;
				E[l].w = sqrt(pow(N[j].x - N[k].x, 2.0) + pow(N[j].y - N[k].y, 2.0));
			}
		}
		
		sort(E, E + l);

		for (int j = 0; j < l; ++j) {

			E[j].x = getRoot(E[j].x);
			E[j].y = getRoot(E[j].y);

			if (E[j].x != E[j].y) {

				if (E[j].w <= r) { road += E[j].w; }
				else { ++state, rail += E[j].w; }
				city[E[j].y] = E[j].x;
			}
		}

		cout << "Case #" << i << ": " << state << " "
			 << (int)(road + 0.5) << " " << (int)(rail + 0.5) << endl;
	}

	return 0;
}