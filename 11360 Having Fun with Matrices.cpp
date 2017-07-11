#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, matrix[10][10], a, b;

void interchange(char sign) {

	cin >> a >> b;
	--a, --b;

	for (int j = 0; j < N; ++j) { 
		
		if(sign=='r'){ swap(matrix[a][j], matrix[b][j]); }
		else{ swap(matrix[j][a], matrix[j][b]); }
	}	
}

void inc(int value) {

	for (int j = 0; j < N; ++j) {

		for (int k = 0; k < N; ++k) {

			matrix[j][k] += value;

			if (matrix[j][k] == 10) { matrix[j][k] = 0; }
			else if (matrix[j][k] == -1) { matrix[j][k] = 9; }
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, M;
	string entry, operation;

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> N;

		for (int j = 0; j < N; ++j) {

			cin >> entry;

			for (int k = 0; k < N; ++k) {
								
				matrix[j][k] = entry[k] - '0';
			}
		}
		
		cin >> M;

		for (int j = 1; j <= M; ++j) {

			cin >> operation;

			if (operation == "row") { interchange('r'); }
			else if (operation == "col") { interchange('c'); }
			else if (operation == "inc") { inc(1); }
			else if (operation == "dec") { inc(-1); }
			else {

				for (int k = 0; k < N; ++k) {

					for (int l = 0; l < N; ++l) {

						if (k < l) { swap(matrix[k][l], matrix[l][k]); }
					}
				}
			}
		}

		cout << "Case #" << i << endl;

		for (int j = 0; j < N; ++j) {

			for (int k = 0; k < N; ++k) {

				cout << matrix[j][k];
			}

			cout << endl;
		}

		cout << endl;
	}

	return 0;
}