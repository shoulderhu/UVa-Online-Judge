#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string R;
	unordered_map<char, int> Map = { { '0', 0 }, { '1', 1 }, { '2', 2 }, 
	                                 { '3', 3 }, { '4', 4 }, { '5', 5 },
									 { '6', 6 }, { '7', 7 }, { '8', 8 },
									 { '9', 9 }, { 'A', 10 }, { 'B', 11 },
									 { 'C', 12 }, { 'D', 13 }, { 'E', 14 }, 
									 { 'F', 15 }, { 'G', 16 }, { 'H', 17 }, 
									 { 'I', 18 }, { 'J', 19 }, { 'K', 20 },
									 { 'L', 21 }, { 'M', 22 }, { 'N', 23 },
									 { 'O', 24 }, { 'P', 25 }, { 'Q', 26 },
									 { 'R', 27 }, { 'S', 28 }, { 'T', 29 },
									 { 'U', 30 }, { 'V', 31 }, { 'W', 32 }, 
									 { 'X', 33 }, { 'Y', 34 }, { 'Z', 35 },
									 { 'a', 36 }, { 'b', 37 }, { 'c', 38 },
									 { 'd', 39 }, { 'e', 40 }, { 'f', 41 },
									 { 'g', 42 }, { 'h', 43 }, { 'i', 44 },
									 { 'j', 45 }, { 'k', 46 }, { 'l', 47 },
									 { 'm', 48 }, { 'n', 49 }, { 'o', 50 },
									 { 'p', 51 }, { 'q', 52 }, { 'r', 53 },
									 { 's', 54 }, { 't', 55 }, { 'u', 56 },
									 { 'v', 57 }, { 'w', 58 }, { 'x', 59 },
									 { 'y', 60 }, { 'z', 61 } };

	while (cin >> R) {

		int N = 1;
		bool isPossible = false;
		vector<int> Vec(R.size());
		
		for (int i = 0; i < R.size(); ++i) { 
			
			Vec[i] = Map[R[i]];
			N = max(N, Vec[i]);
		}
		
		for (int i = N + 1; i < 63; ++i) {

			long long int Dec = 0;

			for (int j = 0; j < R.size(); ++j) {

				Dec = (Dec * i + Vec[j]) % (i - 1);
			}

			if (Dec == 0) {

				cout << i << endl;
				isPossible = true;
				break;
			}
		}

		if (!isPossible) { cout << "such number is impossible!" << endl; }
	}
	
	return 0;
}