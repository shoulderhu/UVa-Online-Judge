#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

long long int Mod(int p) {

	if (p == 0) { return 1; }
	else if (p % 2 == 0) {

		return Mod(p / 2) * Mod(p / 2) % 131071;
	}
	else { return Mod(p - 1) * 2 % 131071; }
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	char digit;
	stack<int> binary;

	while (cin >> digit) {

		long long int decimal = 0;

		if (digit != '#') { binary.push(digit - '0'); }
		else {

			int pos = 0;

			while (binary.empty() == false) {
				
				if (binary.top() == 1) { decimal += Mod(pos); }

				binary.pop(), ++pos;
			}

			decimal % 131071 == 0 ? cout << "YES\n" : cout << "NO\n";
		}
	}

	return 0;
}