#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int Case, M, N;
unordered_map<string, string> Map;

struct link {

	int E;
	string B, C;

	bool operator<(struct link &l) {

		return E < l.E;
	}
}Link[50000];

inline string getRoot(string l) {

	if (Map[l] == l) { return l; }
	else { return Map[l] = getRoot(Map[l]); }
}

int main() {

	ios::sync_with_stdio(false);
	
	cin >> Case;

	for (int i = 0; i < Case; ++i) {

		if (i > 0) { 
			
			cout << endl;
			Map.clear();
		}

		cin >> M >> N;

		for (int j = 0; j < N; ++j) {

			cin >> Link[j].B >> Link[j].C >> Link[j].E;
			Map[Link[j].B] = Link[j].B;
			Map[Link[j].C] = Link[j].C;
		}

		sort(Link, Link + N);

		int cost = 0;

		for (int j = 0; j < N; ++j) {

			Link[j].B = getRoot(Link[j].B);
			Link[j].C = getRoot(Link[j].C);

			if (Link[j].B != Link[j].C) {

				Map[Link[j].C] = Link[j].B;
				cost += Link[j].E;
			}
		}

		cout << cost << endl;
	}
	
	return 0;
}