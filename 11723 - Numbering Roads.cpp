#include <cmath>
#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int R, N, Case = 0, suffix;

	while (cin >> R >> N && !(R == 0 && N == 0)) {

		cout << "Case " << ++Case << ": ";

		if ((R -= N) <= 0) {

			cout << 0 << '\n';
		}
		else if ((suffix = ceil(R / (double)N)) > 26) {

			cout << "impossible\n";
		}
		else { cout << suffix << '\n'; }		
	}

	return 0;
}