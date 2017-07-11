#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int L;
	string S;

	while (cin >> L && L != 0) {

		cin >> S;

		if (S.find('Z') != string::npos) { cout << 0 << endl; continue; }

		size_t pos = S.find_first_not_of("."), p, Min = 2000000;

		while ((p = S.find_first_not_of(".", pos + 1)) != string::npos) {

			if (S[p] != S[pos]) { Min = min(Min, p - pos); }
			pos = p;
		}

		cout << Min << endl;
	}

	return 0;
}
