#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

bool isPalindrome1(string L, double size) {

	int pos = size - 1;

	for (int j = 0; j < size / 2; ++j, --pos) {

		if (L[j] != L[pos]) { return false; }
	}

	return true;
}

bool isPalindrome2(string L, double size, double Sqrt) {

	for (int j = 0; j < size / 2; ++j) {
	
		int pos = size - 1 - j;

		for (int k = j; k < size; k += Sqrt, pos -= Sqrt) {

			if (L[k] != L[pos]) { return false; }
		}
	}

	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	string L;

	cin >> T, cin.ignore();

	for (int i = 1; i <= T; ++i) {

		getline(cin, L);

		for (auto iter = L.begin(); iter != L.end(); ) {

			if (isalpha(*iter) != 0) { ++iter; }
			else { iter = L.erase(iter); }
		}

		cout << "Case #" << i << ":" << endl;

		double Sqrt = sqrt((double)L.size());
		bool isMagic = true;

		if (Sqrt != sqrt(L.size())) { isMagic = false; }

		if (isMagic == true) { 
			
			if (isPalindrome1(L, L.size()) == false || 
				isPalindrome2(L, L.size(), Sqrt) == false) {

				isMagic = false;
			}
		}

		isMagic == true ? cout << (int)Sqrt << endl : cout << "No magic :(" << endl;
	}

	return 0;
}