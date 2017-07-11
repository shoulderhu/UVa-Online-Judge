#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int P[2], p[3];
set<int> Set;

bool isFound(int begin) {

	for (int i = begin; i <= 52; ++i) {

		if (Set.find(i) == Set.end()) {
						
			cout << i << endl;
			return true;
		}
	}

	return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> p[0] >> p[1] >> p[2] >> P[0] >> P[1] &&
		   (p[0] != 0 || p[1] != 0 || p[2] != 0 || P[0] != 0 || P[1] != 0)) {
		
		sort(P, P + 2), sort(p, p + 3);
		Set.clear(), Set.insert(P, P + 2), Set.insert(p, p + 3);		
		
		if (P[0] > p[2] && isFound(1)) { continue; }
		if (P[0] > p[1] && isFound(p[1] + 1)) { continue; }
		if (P[1] > p[2] && isFound(p[2] + 1)) { continue; }

		cout << "-1" << endl;
	}

	return 0;
}