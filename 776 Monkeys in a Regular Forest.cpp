#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int output[1000][1000], number = 0, row = -1, column;
char matrix[1000][1000], c;
bool isVisit[1000][1000];

void DFS(int i, int j, char& c, int& number) {

	if (i < 0 || j < 0 || i > row || j > column || isVisit[i][j] == true
		                                        || matrix[i][j] != c) { return; }
	else {

		output[i][j] = number;
		isVisit[i][j] = true;
		DFS(i - 1, j - 1, c, number);
		DFS(i - 1, j, c, number);
		DFS(i - 1, j + 1, c, number);
		DFS(i, j - 1, c, number);
		DFS(i, j + 1, c, number);
		DFS(i + 1, j - 1, c, number);
		DFS(i + 1, j, c, number);
		DFS(i + 1, j + 1, c, number);
	}
}

void Output() {

	size_t size[1000];

	for (int i = 0; i <= row; ++i) {

		for (int j = 0; j <= column; ++j) {

			isVisit[i][j] = false;
		}
	}

	for (int i = 0; i <= column; ++i) { size[i] = 0; }

	for (int i = 0; i <= row; ++i) {

		for (int j = 0; j <= column; ++j) {

			if (isVisit[i][j] == false) {

				DFS(i, j, matrix[i][j], ++number);
			}
		}
	}
	
	for (int i = 0; i <= row; ++i) {

		for (int j = 0; j <= column; ++j) {

			size[j] = max(size[j], to_string(output[i][j]).size());
		}
	}
	
	for (int i = 0; i <= row; ++i, cout << endl) {

		for (int j = 0; j <= column; ++j) {

			if (j != 0) { cout << " "; }
			cout << setw(size[j]) << output[i][j];			
		}		
	}

	cout << "%" << endl;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string line;

	while (getline(cin, line)) {
				
		if (line == "%") {
			
			Output();
			row = -1, number = 0;
		}
		else {

			stringstream ss(line);
			++row, column = -1;
			while (ss >> c) { matrix[row][++column] = c; }
		}
	}
			
	Output();
			
	return 0;
}