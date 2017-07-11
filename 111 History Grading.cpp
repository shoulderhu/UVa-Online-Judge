#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, o, lcs[21][21];
	vector<int> correct(n);

	cin >> n;

	for (int i = 1; i <= n; ++i) { 
		
		cin >> o;
		correct[o - 1] = i;
	}

	lcs[0][0] = 0;
	for (int i = 1; i < 21; ++i) { lcs[i][0] = 0, lcs[0][i] = 0; }
	
	while (cin >> o) {
		
		vector<int> response(n);
		response[o - 1] = 1;

		for (int i = 2; i <= n; ++i) {

			cin >> o;
			response[o - 1] = i;
		}

		for (int i = 0; i < n; ++i) {

			for (int j = 0; j < n; ++j) {

				if (correct[i] == response[j]) {

					lcs[i + 1][j + 1] = lcs[i][j] + 1;
				}
				else { lcs[i + 1][j + 1] = max(lcs[i + 1][j], lcs[i][j + 1]); }
			}
		}

		cout << lcs[n][n] << endl;
	}
	
	return 0;
}