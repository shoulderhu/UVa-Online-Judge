#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int L, H, R, left = 10000, right = -1;
	int bottom[10000];
	bool isFirst = true;

	memset(bottom, 0, sizeof(bottom));

	while (cin >> L >> H >> R) {

		left = min(left, L);
		right = max(right, R);

		for (int i = L; i < R; ++i) {

			bottom[i] = max(bottom[i], H);
		}		
	}
	
	for (int i = left; i <= right; ++i) {

		if (bottom[i] != bottom[i - 1]) {

			if (isFirst) { isFirst = false; }
			else { cout << ' '; }
			cout << i << ' ' << bottom[i];
		}
	}

	cout << '\n';

	return 0;
}