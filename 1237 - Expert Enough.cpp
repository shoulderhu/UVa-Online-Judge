#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, D, Q, P, two;	
	string maker;

	struct mlh { 
		
		int L, H;
		string M;
	}MLH[10000];

	cin >> T;

	for (int i = 0; i < T; ++i) {

		if (i > 0) { cout << "\n"; }

		cin >> D;

		for (int j = 0; j < D; ++j) {

			cin >> MLH[j].M >> MLH[j].L >> MLH[j].H;
		}

		cin >> Q;

		for (int j = 0; j < Q; ++j) {

			cin >> P;
			two = 0;

			for (int k = 0; k < D; ++k) {

				if (MLH[k].L <= P && P <= MLH[k].H) {

					if (++two == 2) { break; }
					maker = MLH[k].M;
				}
			}

			if (two == 1) { cout << maker << "\n"; }
			else { cout << "UNDETERMINED" << "\n"; }
		}
	}

	return 0;
}