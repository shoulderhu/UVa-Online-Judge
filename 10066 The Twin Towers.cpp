#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N1, N2, n, lcs[101][101], tower = 0;

	while (cin >> N1 >> N2 && (N1 != 0 || N2 != 0)) {

		vector<int> n1, n2;

		for (int i = 1; i <= N1; ++i) {

			cin >> n;
			n1.push_back(n);
		}

		for (int i = 1; i <= N2; ++i) {

			cin >> n;
			n2.push_back(n);
		}

		int size1 = n1.size(), size2 = n2.size();

		for (int i = 0; i < size1; ++i) {

			for (int j = 0; j < size2; ++j) {

				lcs[i][j] = 0;
			}
		}

		for (int i = 0; i < size1; ++i) {

			for (int j = 0; j < size2; ++j) {

				if (n1[i] == n2[j]) { lcs[i + 1][j + 1] = lcs[i][j] + 1; }
				else { lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]); }
			}
		}

		cout << "Twin Towers #" << ++tower << endl;
		cout << "Number of Tiles : " << lcs[size1][size2] << endl << endl;
	}
	
	return 0;
}