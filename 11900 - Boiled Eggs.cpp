#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T, n, P, Q;
	
	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> n >> P >> Q;

		int egg = 0, gm = 0;
		vector<int> N(n);

		for (int i = 0; i < n; ++i) { cin >> N[i]; }

		sort(N.begin(), N.end());

		for (int i = 0; i < N.size(); ++i) {

			if (egg + 1 <= P && gm + N[i] <= Q) {

				++egg, gm += N[i];
			}
			else { break; }
		}

		cout << "Case " << i << ": " << egg << endl;
	}

	return 0;
}
