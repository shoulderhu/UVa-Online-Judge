#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, x, y, z, t;
	
	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> x >> y >> z;		
		cout << (2 * x - y) * z / (x + y) << '\n';		
	}

	return 0;
}