#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, H, dataSet;

	cin >> dataSet;

	for (int i = 1; i <= dataSet; ++i) {

		if (i > 1) { cout << endl; }

		cin >> N >> H;

		int end = N - H;
		string str;

		for (int j = 1; j <= end; ++j) { str += "0"; }
		for (int j = 1; j <= H; ++j) { str += "1"; }

		do {
			cout << str << endl;

		} while (next_permutation(str.begin(), str.end()) == true);
	}
	
	return 0;
}