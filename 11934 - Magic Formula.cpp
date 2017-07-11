#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, d, L, fx, answer;

	while (cin >> a >> b >> c >> d >> L && !(a == 0 && b == 0 && c == 0 && d == 0 && L == 0)) {

		answer = 0;

		for (int i = 0; i <= L; ++i) {

			fx = a*i*i + b*i + c;
			if (fx%d == 0) { ++answer; }
		}

		cout << answer << '\n';
	}

	return 0;
}