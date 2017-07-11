#include <iostream>
#include <cstring>

using namespace std;

int Case, d;
long long s1, N;
bool digit[10];

inline bool isRepeat(long long num) {

	memset(digit, true, sizeof(digit));
	
	while (num > 0) {
		
		d = num % 10;		
		if (digit[d] == false) { return true; }
		num /= 10, digit[d] = false;
	}

	return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> Case;
	
	for (int i = 0; i < Case; ++i) {

		if(i > 0) { cout << '\n'; }

		cin >> N;

		for (int j = 1; ; ++j) {

			if ((s1 = N * j) > 9876543210) { break; }

			if (isRepeat(j) == false && isRepeat(s1) == false) {

				cout << s1 << " / " << j << " = " << N << '\n';
			}
		}
	}

	return 0;
}