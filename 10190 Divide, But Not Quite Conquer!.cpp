#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	while (cin >> n >> m) {
		
		if (n < 2 || m < 2) { cout << "Boring!" << endl; continue; }
		
		int N = n;
		bool isBoring = false;
		vector<int> a;
		
		while (n != 1) {

			if (n%m != 0) { isBoring = true; break; }
			else { n /= m, a.push_back(n); }
		}

		if (isBoring) { cout << "Boring!" << endl; }
		else {

			cout << N;
			for (int i = 0; i < a.size(); ++i) { cout << " " << a[i]; }
			cout << endl;
		}		
	}

	return 0;
}
