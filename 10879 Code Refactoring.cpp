#include <iostream>
#include <cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, K, Ans[4];

	cin >> N;

	for (int i = 1; i <= N; ++i) {

		cin >> K;

		int k = K, l = -1;
		double Sqrt = sqrt((double)k);

		for (int j = 2; j <= Sqrt && l != 3; ++j) {

			if (k%j == 0) { Ans[++l] = j, Ans[++l] = k / j; }
		}

		cout << "Case #" << i << ": " << K << " = " << Ans[0] << " * " << Ans[1] << " = "
			                                        << Ans[2] << " * " << Ans[3] << endl;		
	}

	return 0;
}