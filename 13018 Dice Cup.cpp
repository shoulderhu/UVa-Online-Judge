#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	bool isBL = false;

	while (cin >> N >> M) {

		if (isBL == false) { isBL = true; }
		else { cout << endl; }

		int Max = 0;
		map<int, int> sum;

		for (int i = 1; i <= N; ++i) {

			for (int j = 1; j <= M; ++j) {

				++sum[i + j];
				Max = max(sum[i + j], Max);
			}
		}

		for (auto iter = sum.begin(); iter != sum.end(); ++iter) {

			if (iter->second == Max) { cout << iter->first << endl; }
		}
	}

	return 0;
}