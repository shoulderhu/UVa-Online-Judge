#include <iostream>

using namespace std;

int S, T, N;

void ptintCeil(int &length) {

	for (int i = 0; i < T; ++i, cout << endl) {

		for (int j = 0; j < length; ++j) {

			cout << "*";
		}
	}
}

void printFloor() {

	for (int i = 0; i < S; ++i, cout << endl) {
		
		for (int k = 0; k < N; ++k) {

			for (int j = 0; j < T; ++j) { cout << "*"; }
			for (int j = 0; j < S; ++j) { cout << "."; }
		}

		for (int j = 0; j < T; ++j) { cout << "*"; }
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace = 0;

	while (cin >> S >> T >> N && (S != 0 || T != 0 || N != 0)) {

		int length = (N + 1)*T + N*S;

		cout << "Case " << ++kace << ":" << endl;

		for (int i = 0; i < N; ++i) {

			ptintCeil(length);
			printFloor();
		}

		ptintCeil(length);
		cout << endl;
	}

	return 0;
}