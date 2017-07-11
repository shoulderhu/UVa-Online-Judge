#include <iostream>
#include <string>

using namespace std;

int side;
char matrix[101][101];
string word;

bool upperLeft(int i, int j) {
	
	for (int k = 1; k < word.size(); ++k, --i, --j) {

		if (i < 1 || j < 1 || matrix[i][j] != word[k]) { return false; }
	}

	return true;
}

bool upperMid(int i, int j) {

	for (int k = 1; k < word.size(); ++k, --i) {

		if (i < 1 || matrix[i][j] != word[k]) { return false; }
	}

	return true;
}

bool upperRight(int i, int j) {

	for (int k = 1; k < word.size(); ++k, --i, ++j) {

		if (i < 1 || j > side || matrix[i][j] != word[k]) { return false; }
	}

	return true;
}

bool left(int i, int j) {

	for (int k = 1; k < word.size(); ++k, --j) {

		if (j < 1 || matrix[i][j] != word[k]) { return false; }
	}

	return true;
}

bool right(int i, int j) {

	for (int k = 1; k < word.size(); ++k, ++j) {

		if (j > side || matrix[i][j] != word[k]) { return false; }
	}

	return true;
}

bool lowerLeft(int i, int j) {

	for (int k = 1; k < word.size(); ++k, ++i, --j) {

		if (i > side || j < 1 || matrix[i][j] != word[k]) { return false; }
	}

	return true;
}

bool lowerMid(int i, int j) {

	for (int k = 1; k < word.size(); ++k, ++i) {

		if (i > side || matrix[i][j] != word[k]) { return false; }
	}

	return true;
}

bool lowerRight(int i, int j) {

	for (int k = 1; k < word.size(); ++k, ++i, ++j) {

		if (i > side || j > side || matrix[i][j] != word[k]) { return false; }
	}

	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	cin >> side;

	for (int i = 1; i <= side; ++i) {

		for (int j = 1; j <= side; ++j) {

			cin >> matrix[i][j];
		}
	}

	while (cin >> word && word != "0") {

		bool isFound = false;

		for (int i = 1; i <= side; ++i) {

			for (int j = 1; j <= side; ++j) {

				if (matrix[i][j] == word[0]) {

					if (upperLeft(i - 1, j - 1) == true) {
						
						cout << i << "," << j << " " << i - word.size() + 1 << "," << j - word.size() + 1 << endl;
						isFound = true; break;
					}
					else if (upperMid(i - 1, j) == true) {

						cout << i << "," << j << " " << i - word.size() + 1 << "," << j << endl;
						isFound = true; break;
					}
					else if (upperRight(i - 1, j + 1) == true) {
					
						cout << i << "," << j << " " << i - word.size() + 1 << "," << j + word.size() - 1 << endl;
						isFound = true; break;
					}
					else if (left(i, j - 1) == true) {
					
						cout << i << "," << j << " " << i << "," << j - word.size() + 1 << endl;
						isFound = true; break;
					}
					else if (right(i, j + 1) == true) {
					
						cout << i << "," << j << " " << i << "," << j + word.size() - 1 << endl;
						isFound = true; break;
					}
					else if (lowerLeft(i + 1, j - 1) == true) {
					
						cout << i << "," << j << " " << i + word.size() - 1 << "," << j - word.size() + 1 << endl;
						isFound = true; break;
					}
					else if (lowerMid(i + 1, j) == true) {
					
						cout << i << "," << j << " " << i + word.size() - 1 << "," << j << endl;
						isFound = true; break;
					}
					else if (lowerRight(i + 1, j + 1) == true) {
					
						cout << i << "," << j << " " << i + word.size() - 1 << "," << j + word.size() - 1 << endl;
						isFound = true; break;
					}
				}
			}

			if (isFound == true) { break; }
		}

		if (isFound == false) { cout << "Not found" << endl; }
	}

	return 0;
}