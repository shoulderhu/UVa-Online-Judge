#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, A;

	while (cin >> N >> A) {

		int begin = 0;		
		vector<int> exp(179, 0);
		vector<int> value(179, 0);
		exp[178] = 1;

		for (int i = 1; i <= N; ++i) {

			int carry = 0;

			for (int j = 178; j >= 0; --j) {

				exp[j] = exp[j] * A + carry;
				carry = 0;

				if (exp[j] > 9) {

					carry = exp[j] / 10;
					exp[j] %= 10;
				}
			}

			vector<int> expCpy = exp;
			carry = 0;

			for (int j = 178; j >= 0; --j) {

				expCpy[j] = expCpy[j] * i + carry;
				carry = 0;

				if (expCpy[j] > 9) {

					carry = expCpy[j] / 10;
					expCpy[j] %= 10;
				}
			}

			for (int j = 178; j >= 0; --j) {

				value[j] += expCpy[j];

				if (value[j] > 9) {

					++value[j - 1];
					value[j] -= 10;
				}
			}
		}

		while (value[begin] == 0 && begin != 178) { ++begin; }
		for (int j = begin; j < 179; ++j) { cout << value[j]; }
		cout << endl;
	}

	return 0;
}