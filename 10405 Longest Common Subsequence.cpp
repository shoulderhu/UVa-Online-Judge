#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int lcs[1001][1001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string first, second;

	while (getline(cin, first)) {

		getline(cin, second);

		int length1 = first.size(), length2 = second.size();

		for (int i = 0; i < length1; ++i) {

			for (int j = 0; j < length2; ++j) {

				lcs[i][j] = 0;
			}
		}
				
		for (int i = 0; i < length1; ++i) {

			for (int j = 0; j < length2; ++j) {

				if (first[i] == second[j]) { lcs[i + 1][j + 1] = lcs[i][j] + 1; }
				else { lcs[i + 1][j + 1] = max(lcs[i + 1][j], lcs[i][j + 1]); }
			}
		}

		cout << lcs[length1][length2] << endl;
	}

	return 0;
}