#include <iostream>
#include <string>

using namespace std;

int main() {

	int T, N;
	string field;

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> N >> field;

		int scarecrow = 0;

		for (int j = 1; j <= N; ++j) {

			if (field[j - 1] == '.') { ++scarecrow, j += 2; }
		}

		cout << "Case " << i << ": " << scarecrow << endl;
	}
	
	return 0;
}