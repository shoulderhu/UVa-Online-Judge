#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int pos, comb[3];

	while (cin >> pos >> comb[0] >> comb[1] >> comb[2]) {

		int degree = 1080;

		if (pos == 0 && comb[0] == 0 && comb[1] == 0 && comb[2] == 0) { break; }

		if (comb[0] > pos) { degree += (40 - comb[0] + pos) * 9; }
		else { degree += (pos - comb[0]) * 9; }

		if (comb[0] > comb[1]) { degree += (40 - comb[0] + comb[1]) * 9; }
		else { degree += (comb[1] - comb[0]) * 9; }

		if (comb[2] > comb[1]) { degree += (40 - comb[2] + comb[1]) * 9; }
		else { degree += (comb[1] - comb[2]) * 9; }

		cout << degree << endl;
	}

	return 0;
}
