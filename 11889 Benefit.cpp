#include <iostream>

using namespace std;

inline int GCD(int A, int B) { return B == 0 ? A : GCD(B, A%B); }

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, A, C;

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> A >> C;

		if (C%A != 0) { cout << "NO SOLUTION" << endl; }
		else {
			
			int m = C / A, B = m;
			
			while (B / GCD(A, B) != m) { B += m; }
			cout << B << endl;
		}
	}

	return 0;
}