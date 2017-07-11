#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, F, bill = 0;
	string V;
	
	while (cin >> N >> F && (N != 0 || F != 0)) {

		int bit = 0, p = 0;
		bool isPrint = false;
		vector<int> S(24, 0), P;

		for (int i = 0; i < N; ++i) {

			cin >> V;

			auto jter = S.rbegin();

			for (auto iter = V.rbegin(); iter != V.rend(); ++iter, ++jter) {

				*jter += *iter - '0';				
			}

			for (int j = 23; j >= 0; --j) {

				if (S[j] > 9) { S[j - 1] += S[j] / 10, S[j] %= 10; }
			}
		}

		cout << "Bill #" << ++bill << " costs ";

		while (S[bit] == 0) { ++bit; }
		for (int i = bit; i < 24; ++i) { cout << S[i]; }

		cout << ": each friend should pay ";		
		
		for (int i = bit; i < 24; ++i) {

			p = p * 10 + S[i];
			P.push_back(p / F);			
			p %= F;
		}
		
		for (auto iter = P.begin(); iter != P.end(); ++iter) {

			if (*iter != 0) {

				for (auto jter = iter; jter != P.end(); ++jter) { cout << *jter; }
				isPrint = true;
				break;
			}
		}
		
		if (!isPrint) { cout << "0"; }

		cout << endl << endl;
	}

	return 0;
}