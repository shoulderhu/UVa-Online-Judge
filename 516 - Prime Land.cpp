#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int prime[3512], p = -1, x, e;
bool isPrime[32768];
string line;
stringstream ss;

int main() {

	ios::sync_with_stdio(false);

	memset(isPrime, true, sizeof(isPrime));

	for (int i = 2; i < 32768; ++i) {

		if (isPrime[i]) {

			prime[++p] = i;

			for (int j = i + i; j < 32768; j += i) {

				isPrime[j] = false;
			}
		}
	}
	
	while (getline(cin, line) && line != "0") {

		x = 1;
		ss.clear(), ss << line;
		while (ss >> p >> e) { x *= pow(p, e); }
		--x;

		for (int i = 3511; i >= 0; --i) {
			
			e = 0;
			
			while (x % prime[i] == 0) {

				++e;
				x /= prime[i];				
			}

			if (e != 0) {

				cout << prime[i] << " " << e;
				if (x == 1) { cout << endl; break; }
				else { cout << " "; }
			}
		}
	}

	return 0;
}