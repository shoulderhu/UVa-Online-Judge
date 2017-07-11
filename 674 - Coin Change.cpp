#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	
	int coin[] = { 1, 5, 10, 25, 50 }, money;
	long long int way[7490] = { 1 };

	for (int i = 0; i < 5; ++i) {

		for (int j = 0; j + coin[i] < 7490; ++j) {

			way[j + coin[i]] += way[j];
		}
	}

	while (cin >> money) {

		cout << way[money] << endl;
	}

	return 0;
}