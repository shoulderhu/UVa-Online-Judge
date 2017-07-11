#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int C, S, X = 0;
	int s[10];
	double AM, imbalance;
	
	while (cin >> C >> S) {
		
		AM = 0, imbalance = 0;
		memset(s, 0, sizeof(s));

		for (int i = 0; i < S; ++i) {

			cin >> s[i];
			AM += s[i];
		}
		
		AM /= C;
		sort(s, s + 2 * C);
		cout << "Set #" << ++X << "\n";
		
		for (int i = 0; i < C; ++i) {

			cout << ' ' << i << ':';
			if (s[i] != 0) { cout << ' ' << s[i]; }
			if (s[2 * C - i - 1] != 0) { cout << ' ' << s[2 * C - i - 1]; }
			cout << '\n';
			imbalance += fabs(s[i] + s[2 * C - i - 1] - AM);
		}
		
		cout << fixed << setprecision(5) << "IMBALANCE = " << imbalance << "\n\n";		
	}

	return 0;
}