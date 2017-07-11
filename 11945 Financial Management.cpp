#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	double balance;

	cin >> N;

	for (int i = 1; i <= N; ++i) {

		double sum = 0;

		for (int j = 0; j < 12; ++j) {

			cin >> balance;
			sum += balance;
		}

		sum = (sum / 12 * 100 + 0.5) / 100;

		string str = to_string(sum);
		int pos = str.find('.');

		while (pos - 3 > 0) { str.insert(pos - 3, ","), pos -= 3; }

		cout << i << " $" << str.substr(0, str.size() - 4) << endl;
	}

	return 0;
}
