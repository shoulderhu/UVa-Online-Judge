#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int town[751], Case, N, M, X, Y;
struct node { int x, y; }Node[751];

struct edge { 
	
	int x, y;
	double w;

	bool operator<(struct edge &e) {

		return w < e.w;
	}
}Edge[499500];

inline int getRoot(int &e) {

	if (town[e] == e) { return e; }
	else { return town[e] = getRoot(town[e]); }
}

inline bool isNeed() {

	int t = 0;

	for (int i = 1; i <= N; ++i) {

		if (town[i] == i && ++t > 1) {

			return true;
		}
	}

	return false;
}

int main() {

	ios::sync_with_stdio(false);
	
	cin >> Case;

	for (int i = 0; i < Case; ++i) {

		if (i > 0) { cout << endl; }

		cin >> N;

		for (int j = 1; j <= N; ++j) {

			town[j] = j;
			cin >> Node[j].x >> Node[j].y;
		}		
		
		cin >> M;

		for (int j = 0; j < M; ++j) {

			cin >> Edge[j].x >> Edge[j].y;
			Edge[j].w = sqrt(pow(Node[Edge[j].x].x - Node[Edge[j].y].x, 2.0) +
				             pow(Node[Edge[j].x].y - Node[Edge[j].y].y, 2.0));
		}

		sort(Edge, Edge + M);

		for (int j = 0; j < M; ++j) {

			X = getRoot(Edge[j].x), Y = getRoot(Edge[j].y);
			if (X != Y) { town[Y] = X; }
		}

		if (!isNeed()) { cout << "No new highways need" << endl; continue; }

		int l = 0;

		for (int j = 1; j <= N; ++j) {

			for (int k = j + 1; k <= N; ++k, ++l) {

				Edge[l].x = j, Edge[l].y = k;
				Edge[l].w = sqrt(pow(Node[Edge[l].x].x - Node[Edge[l].y].x, 2.0) +
				                 pow(Node[Edge[l].x].y - Node[Edge[l].y].y, 2.0));
			}
		}

		sort(Edge, Edge + l);

		for (int j = 0; j < l; ++j) {

			X = getRoot(Edge[j].x);
			Y = getRoot(Edge[j].y);

			if (X != Y) {

				town[Y] = X;
				cout << Edge[j].x << " " << Edge[j].y << endl;				
				if (!isNeed()) { break; }
			}
		}
	}

	return 0;
}