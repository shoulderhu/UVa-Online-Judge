#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int index = 0, lcs[101][101], map[101][101];
	string word;
	vector<string> text[2];

	lcs[0][0] = 0, map[0][0] = 0;
	for (int i = 1; i <= text[0].size(); ++i) { lcs[i][0] = 0, map[i][0] = 0; }
	for (int i = 1; i <= text[1].size(); ++i) { lcs[0][i] = 0, map[0][i] = 0; }

	while (cin >> word) {

		if (word != "#") { text[index].push_back(word); }
		else {

			if (index == 0) { ++index; }
			else {

				for (int i = 0; i < text[0].size(); ++i) {

					for (int j = 0; j < text[1].size(); ++j) {

						if (text[0][i] == text[1][j]) {

							lcs[i + 1][j + 1] = lcs[i][j] + 1;
							map[i + 1][j + 1] = 3;
						}
						else if (lcs[i + 1][j] > lcs[i][j + 1]) { 
							
							lcs[i + 1][j + 1] = lcs[i + 1][j];
							map[i + 1][j + 1] = 2;
						}
						else {

							lcs[i + 1][j + 1] = lcs[i][j + 1];
							map[i + 1][j + 1] = 1;
						}
					}
				}

				int x = text[0].size(), y = text[1].size();
				vector<string> LCS;

				while (x != 0 && y != 0) {

					if (map[x][y] == 3) {

						LCS.push_back(text[0][x - 1]);
						--x, --y;
					}
					else if (map[x][y] == 2) { --y; }
					else { --x; }
				}

				cout << LCS[LCS.size() - 1];
				for (int i = LCS.size() - 2; i >= 0; --i) { cout << " " << LCS[i]; }
				cout << endl;

				index = 0, text[0].clear(), text[1].clear();
			}
		}
	}

	return 0;
}
