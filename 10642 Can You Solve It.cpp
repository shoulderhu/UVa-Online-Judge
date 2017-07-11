#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	long long int x1, y1, x2, y2;

	cin >> n;

	for (int i = 1; i <= n; ++i) {

		cin >> x1 >> y1 >> x2 >> y2;
		cout << "Case " << i << ": "
			 << (x1 + y1 + x2 + y2)*(x2 + y2 - x1 - y1 - 1) / 2 + x2 + y2 - x1 + x2
			 << endl;
	}

	return 0;
}

//(x1 + y1 + x2 + y2)*(x2 + y2 - x1 - y1 - 1) / 2 + (x2 + y2 - x1 - y1 - 1) + y1 + x2 + 1