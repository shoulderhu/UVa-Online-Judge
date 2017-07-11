#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, location;
	
	while (cin >> n && n != 0) {

		vector<int> Vec;
		bool isPossible = true;

		for (int i = 0; i < n; ++i) {

			cin >> location;
			Vec.push_back(location);
		}

		sort(Vec.begin(), Vec.end());
		
		for (int i = 0; i < Vec.size() - 1; ++i) {

			if (Vec[i + 1] - Vec[i] > 200) {

				isPossible = false;
				break;
			}
		}

		if (isPossible == true && (1422 - Vec[n - 1]) * 2 > 200) { 
			
			isPossible = false;
		}

		isPossible == true ? cout << "POSSIBLE" << endl : cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}
