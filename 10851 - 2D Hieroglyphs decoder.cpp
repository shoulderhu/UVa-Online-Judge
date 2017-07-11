#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, size, value;
	int pow2[] = { 0, 1, 2, 4, 8, 16, 32, 64, 128, 256 };
	string matrix[10];

	cin >> N;

	for (int i = 0; i < N; ++i) {

		for (int j = 0; j < 10; ++j) {

			cin >> matrix[j];
		}

		size = matrix[0].size() - 1;

		for (int j = 1; j < size; ++j) {

			value = 0;

			for (int k = 1; k < 9; ++k) {

				if (matrix[k][j] == '\\') {

					value += pow2[k];
				}
			}
			cout << (char)value;
		}

		cout << '\n';
	}

	return 0;
}