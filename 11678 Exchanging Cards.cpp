#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int A, B, card;

	while (cin >> A >> B && A != 0 || B != 0) {

		unordered_set<int> Alice, Betty;

		for (int i = 0; i < A; ++i) {

			cin >> card;
			Alice.insert(card);
		}

		for (int i = 0; i < B; ++i) {

			cin >> card;
			Betty.insert(card);
		}

		for (auto iter = Alice.begin(); iter != Alice.end(); ) {

			if (Betty.find(*iter) == Betty.end()) { ++iter; }
			else { Betty.erase(*iter), Alice.erase(iter++); }
		}

		cout << min(Alice.size(), Betty.size()) << endl;
	}

	return 0;
}