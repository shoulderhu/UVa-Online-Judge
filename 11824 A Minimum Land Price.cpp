#include <iostream>
#include <cmath> 
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, L;

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		int t = 0;
		long long sum = 0;
		vector<int> cost;
		
		while (cin >> L && L != 0) { cost.push_back(L); }
		sort(cost.begin(), cost.end());

		for (int j = cost.size() - 1; j >= 0; --j) { sum += pow(cost[j], ++t); }
		sum *= 2;

		if (sum > 5000000) { cout << "Too expensive" << endl; }
		else { cout << sum << endl; }
	}

	return 0;
}