#include <iostream>
#include <string.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, solution[1001], factorial[2568];

	memset(solution, 0, sizeof(solution)), memset(factorial, 0, sizeof(factorial));	
	factorial[2567] = 1, solution[0] = 1, solution[1] = 1;	

	for (int i = 2; i <= 1000; ++i) {
		
		int carry = 0;

		for (int j = 2567; j >= 0; --j){

			factorial[j] = factorial[j] * i + carry;
			carry = 0;

			if (factorial[j] > 9) {

				carry = factorial[j] / 10;
				factorial[j] %= 10;
			}
		}

		for (int j = 0; j < 2568; ++j) { solution[i] += factorial[j]; }
	}

	while (cin >> n) { cout << solution[n] << endl; }

	return 0;
}