#include <iostream>
#include <cstring>

using namespace std;

int edge[6][4] = { { 0, 0, 0, 0 },
	               { 2, 3, 5, 0 },
                   { 1, 3, 5, 0 },
				   { 1, 2, 4, 5 },
                   { 3, 5, 0, 0 },
				   { 1, 2, 3, 4 } };
bool isVisit[6][6];

inline void DFS(int node, int all, int output) {
	
	if (all == 9) {

		cout << output << '\n';
		return;
	}

	int e;

	for (int i = 0; i < 4; ++i) {

		e = edge[node][i];

		if (!isVisit[node][e]) {

			isVisit[node][e] = true;
			isVisit[e][node] = true;
			DFS(e, all + 1, output * 10 + e);
			isVisit[node][e] = false;
			isVisit[e][node] = false;
		}
	}
}

int main() {
		
	for (int i = 0; i < 6; ++i) {

		isVisit[0][i] = true;
		isVisit[i][0] = true;
	}

	DFS(1, 1, 1);

	return 0;
}