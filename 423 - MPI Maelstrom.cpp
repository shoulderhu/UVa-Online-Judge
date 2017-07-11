#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int n, A[100][100], time = 0;
	string a;

	cin >> n;

	for (int i = 0; i < n; ++i) {

		A[i][i] = 0;

		for (int j = 0; j < i; ++j) {
								
			cin >> a;
			
			if (a == "x") {

				A[i][j] = 1000000000;
				A[j][i] = 1000000000;
			}
			else {

				A[i][j] = stoi(a, nullptr, 10);
				A[j][i] = A[i][j];
			}			
		}
	}

	for (int i = 0; i < n; ++i) {

		for (int j = 0; j < n; ++j) {

			for (int k = 0; k < n; ++k) {

				A[j][k] = min(A[j][k], A[j][i] + A[i][k]);
			}
		}
	}
	
	for (int i = 1; i < n; ++i) {
				
		time = max(A[0][i], time);
	}

	cout << time << endl;
	
	return 0;
}