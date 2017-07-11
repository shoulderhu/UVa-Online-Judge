#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	string a, b;
	
	while (getline(cin, a)) {

		getline(cin, b);

		map<char, int> A, B;
		
		for (int i = 0; i < a.size(); ++i) { ++A[a[i]]; }
		for (int i = 0; i < b.size(); ++i) { ++B[b[i]]; }
		
		for (auto iter = A.begin(); iter != A.end(); ++iter) {

			int Min = min(iter->second, B[iter->first]);
			for (int i = 1; i <= Min; ++i) { cout << iter->first; }			
		}

		cout << endl;		
	}

	return 0;
}
