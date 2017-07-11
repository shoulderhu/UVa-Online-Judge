#include <iostream>
#include <string>

using namespace std;

int main() {

	int N, S, s;
	string M;

	cin >> N;

	for (int i = 0; i < N; ++i) {

		cin >> M >> S;
		
		bool isWonderful = true;
		
		for (int j = 0; j < S; ++j) {

			cin >> s;

			if (isWonderful) {

				int remainder = 0;

				for (int k = 0; k < M.size(); ++k) {

					remainder = (remainder * 10 + (M[k] - '0')) % s;
				}

				if (remainder != 0) { isWonderful = false; }
			}		
		}

		cout << M << " - " << (isWonderful ? "Wonderful" : "Simple") 
			 << "." << endl;
	}

	return 0;
}