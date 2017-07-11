#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, C, R;

	cin >> N;

	for (int i = 1; i <= N; ++i) {

		cin >> C >> R;				
		cout << "Case #" << i << ":";
		
		if (C == R) { cout << " 0" << endl; }
		else {

			set<int> Set;
			C -= R;

			for (int j = 1; j <= sqrt(C); ++j) {

				if (C%j == 0) {
					
					int temp = C / j;

					if (j > R) { Set.insert(j); }
					if (temp > R) { Set.insert(temp); }
				}
			}

			for (auto iter = Set.begin(); iter != Set.end(); ++iter) { cout << " " << *iter; }
			cout << endl;
		}
	}

	return 0;
}