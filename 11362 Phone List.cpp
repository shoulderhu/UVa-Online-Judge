#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	string phone;

	cin >> t;

	for (int i = 1; i <= t; ++i) {

		cin >> n;

		bool isPrefix = false;
		vector<string> catalogue;

		for (int j = 1; j <= n; ++j) {

			cin >> phone;
			catalogue.push_back(phone);
		}

		sort(catalogue.begin(), catalogue.end(), [](string a, string b) {
		
			int aSize = a.size(), bSize = b.size();

			if (aSize != bSize) { return aSize < bSize; }
			else { return a < b; }
		});

		for (int j = 0; j < catalogue.size(); ++j) {

			for (int k = j + 1; k < catalogue.size(); ++k) {

				if (catalogue[k].compare(0, catalogue[j].size(), catalogue[j]) == 0) {

					isPrefix = true; break;
				}
			}

			if (isPrefix == true) { break; }
		}

		isPrefix == false ? cout << "YES" << endl : cout << "NO" << endl;		
	}

	return 0;
}