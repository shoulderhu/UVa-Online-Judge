#include <iostream>
#include <set>

using namespace std;

int main() {

	int i, j, n, k, K[100000];
	multiset<int> urn;

	while (cin >> n && n != 0) {

		long long int total = 0;
		urn.clear();

		for (i = 1; i <= n; i++) {

			cin >> k;

			for (j = 0; j < k; j++) {

				cin >> K[j];
				urn.insert(K[j]);
			}

			multiset<int>::iterator lowBill = urn.begin(), highBill = --urn.end();
			total += *highBill - *lowBill;
			urn.erase(highBill), urn.erase(lowBill);
		}

		cout << total << endl;
	}

	return 0;
}
