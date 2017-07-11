#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, num, fib[45];

	fib[0] = 0, fib[1] = 1;	
	for (int i = 2; i < 45; ++i) { fib[i] = fib[i - 1] + fib[i - 2]; }
	
	cin >> N;

	for (int i = 0; i < N; ++i) {

		int pos = 0;
		vector<int> base;
		
		cin >> num;
		cout << num << " = ";
		
		for (int j = 44; j >= 2; --j) {

			if (num >= fib[j]) {

				base.push_back(1);
				num -= fib[j];
			}
			else { base.push_back(0); }
		}

		while (base[pos] == 0) { ++pos; }
		for (int j = pos; j < base.size(); ++j) { cout << base[j]; }

		cout << " (fib)" << endl;
	}

	return 0;
}