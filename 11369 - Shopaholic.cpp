#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int t, n, p;

	cin >> t;

	for (int i = 0; i < t; ++i){

		cin >> n;

		int discount = 0;
		vector<int> P;

		for (int j = 0; j < n; ++j){

			cin >> p;
			P.push_back(p);
		}

		sort(P.begin(), P.end());

		for (int j = n - 3; j >= 0; j -= 3){ discount += P[j]; }

		cout << discount << endl;
	}

	return 0;
}