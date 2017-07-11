#include <iostream>
#include <string>

using namespace std;

int main() {

	int sets, N;

	cin >> sets;

	for (int i = 0; i < sets; ++i) {

		cin >> N;

		if (N <= 1) { cout << N << endl; continue; }

		string Q = "";

		for (int j = 9; j >= 2; --j) {

			while (N % j == 0) { 
				
				Q.insert(0, to_string(j));
				N /= j;
			}
		}
				
		if (N > 9) { cout << -1 << endl; }
		else { cout << Q << endl; }
	}

	return 0;
}
