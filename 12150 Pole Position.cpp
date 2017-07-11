#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;

	while (cin >> N && N != 0) {

		int move = 0;
		bool isValid = true;
		vector<int> C(N), P(N), S(N, -1);

		for (int i = 0; i < N; ++i) { 
			
			cin >> C[i] >> P[i]; 
			move += P[i];
		}

		if (move != 0) { cout << "-1" << endl; continue; }

		for (int i = 0; i < N; ++i) {

			int pos = i + P[i];

			if (pos < 0 || pos >= N || S[pos] != -1) { 
				
				isValid = false;
				break;
			}			
			else{ S[pos] = C[i]; }			
		}

		if (isValid == false) { cout << "-1" << endl; }
		else {

			cout << S[0];
			for (int i = 1; i < N; ++i) { cout << " " << S[i]; }
			cout << endl;
		}
 	}

	return 0;
}