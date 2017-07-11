#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace, W, y[2];

	cin >> kace;

	for (int i = 1; i <= kace; ++i) {

		if (i > 1) { cout << endl; }

		cin >> W >> y[0] >> y[1];
		
		int gap = y[0] - y[1];
		bool isClosed = true;

		for (int j = 2; j <= W; ++j) {

			cin >> y[0] >> y[1];
			if (y[0] - y[1] != gap) { isClosed = false; }
		}

		isClosed == true ? cout << "yes\n" : cout << "no\n";
	}

	return 0;
}