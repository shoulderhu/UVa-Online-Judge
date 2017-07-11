#include <iostream>

using namespace std;

int k, S[50], s[7];

void DFS(int index, int num) {
	
	s[num] = S[index];

	if (num != 6) {			

		for (int i = index + 1; i <= k; ++i) {

			DFS(i, num + 1);
		}
	}
	else {
		
		cout << s[1];

		for (int i = 2; i < 7; ++i) {

			cout << " " << s[i];
		}

		cout << "\n";		
	}	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	int kk;
	bool isSpaceLine = false;

	while (cin >> k && k != 0) {

		if (!isSpaceLine) { isSpaceLine = true; }
		else { cout << "\n"; }

		for (int i = 1; i <= k; ++i) {

			cin >> S[i];
		}

		kk = k - 5;

		for (int i = 1; i <= kk; ++i) {

			DFS(i, 1);
		}
	}

	return 0;
}