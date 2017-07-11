#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int T, n, score[100000];

	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> n;
		
		for (int j = 0; j < n; ++j) { cin >> score[j]; }

		int Max = score[0] - score[1], senior = max(score[0], score[1]);

		for (int j = 2; j < n; ++j) {

			Max = max(Max, senior - score[j]);
			senior = max(score[j], senior);
		}

		cout << Max << endl;
	}

	return 0;
}
