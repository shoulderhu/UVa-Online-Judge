#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

int table[10];

bool fghij(int i) {

	if (i < 10000) { table[0] = 1; }

	while (i > 0) {

		int digit = i % 10;

		if (table[digit] != 0) { return false; }
		else { table[digit] = 1, i /= 10; }
	}
	
	return true;
}

bool abcde(int j) {

	if (j < 10000 || j > 99999) { return false; }
	
	while (j > 0) {

		int digit = j % 10;

		if (table[digit] != 0) { return false; }
		else { table[digit] = 1, j /= 10; }
	}
	
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	bool isBlank = false;
	
	while (cin >> N && N != 0) {
		
		if (isBlank == false) { isBlank = true; }
		else { cout << endl; }

		bool isPrint = false;

		for (int i = 1234; i <= 99999 / N; i++) {

			memset(table, 0, sizeof(table));

			if (fghij(i) == true && abcde(i*N) == true) {

				cout << i*N << " / " << setfill('0') << setw(5) << i << " = " << N << endl;
				isPrint = true;
			}
		}

		if (isPrint == false) { cout << "There are no solutions for " << N << ".\n"; }
	}

	return 0;
}