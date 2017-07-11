#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int B, N, R, D, C, V;

	while (cin >> B >> N && !(B == 0 && N == 0)) {

		bool isBailout = false;
		vector<int> bank(B + 1, 0);

		for (int i = 1; i <= B; i++) {

			cin >> R;
			bank[i] = R;
		}

		for (int i = 1; i <= N; i++) {

			cin >> D >> C >> V;
			bank[D] -= V, bank[C] += V;
		}

		for (int i = 1; i < bank.size(); i++) {

			if (bank[i] < 0) { isBailout = true; break; }
		}

		isBailout == true ? cout << "N\n" : cout << "S\n";
	}

	return 0;
}