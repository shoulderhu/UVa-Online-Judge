#include <iostream>
#include <iomanip>
#include <deque>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, k, m;

	while (cin >> N >> k >> m && N != 0 || k != 0 || m != 0) {

		bool isComma = false;
		deque<int> K(N), M(N);

		for (int i = 0; i < N; ++i) { K[i] = i + 1, M[i] = N - i; }

		while (!K.empty()) {

			if (!isComma) { isComma = true; }
			else { cout << ","; }

			for (int i = 1; i < k; ++i) {

				K.push_back(K.front()), K.pop_front();
			}

			for (int i = 1; i < m; ++i) {

				M.push_back(M.front()), M.pop_front();
			}

			cout << setw(3) << K.front();

			if (K.front() != M.front()) { 
				
				cout << setw(3) << M.front();
				K.erase(find(K.begin(), K.end(), M.front()));
				M.erase(find(M.begin(), M.end(), K.front()));
			}
			
			K.pop_front(), M.pop_front();
		}

		cout << endl;
	}

	return 0;
}