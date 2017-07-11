#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n, x;
	vector<int> position;

	cin >> t;

	for (int i = 1; i <= t; i++) {

		position.clear();

		cin >> n;

		for (int j = 1; j <= n; j++) { 
			
			cin >> x; 
			position.push_back(x);
		}

		sort(position.begin(), position.end());

		cout << 2 * (*(--position.end()) - *(position.begin())) << endl;
	}
	
	return 0;
}