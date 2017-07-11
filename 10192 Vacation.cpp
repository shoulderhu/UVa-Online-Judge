#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int lcs[101][101], kace = 0;
	string s1, s2;

	while (getline(cin, s1) && s1 != "#") {

		getline(cin, s2);

		int size1 = s1.size(), size2 = s2.size();

		for (int i = 0; i < size1; ++i) {

			for (int j = 0; j < size2; ++j) {

				lcs[i][j] = 0;
			}
		}

		for (int i = 0; i < size1; ++i) {

			for (int j = 0; j < size2; ++j) {

				if (s1[i] == s2[j]) { lcs[i + 1][j + 1] = lcs[i][j] + 1; }
				else { lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]); }
			}
		}

		cout << "Case #" << ++kace << ": you can visit at most "
		                           << lcs[size1][size2] << " cities." << endl;
	}

	return 0;
}