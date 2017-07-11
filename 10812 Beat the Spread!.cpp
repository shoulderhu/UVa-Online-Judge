#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	long long int n, s, d, score[2];

	cin >> n;

	for (int i = 1; i <= n; ++i) {

		cin >> s >> d;

		score[0] = (s + d) / 2, score[1] = (s - d) / 2;

		if (score[0] < 0 || score[1] < 0 || (s + d) % 2 != 0 || (s - d) % 2 != 0) { 
			
			cout << "impossible" << endl; 
		}
		else { cout << score[0] << " " << score[1] << endl; }
	}

	return 0;
}