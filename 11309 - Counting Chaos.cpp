#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string str;

inline bool isPalindromic(int HH, int MM) {

	str.clear();

	if(HH != 0) {
		
		str += to_string(HH);

		if (MM / 10 % 10 == 0) {

			str += "0" + to_string(MM);
		}
		else { str += to_string(MM); }
	}
	else { str += to_string(MM); }
	
	for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {

		if (str[i] != str[j]) { return false; }
	}

	return true;
}

int main() {
		
	cin.tie(0);

	int n, HH, MM;
	bool isFirst, isFind;

	cin >> n;

	for (int k = 0; k < n; ++k) {

		scanf("%d:%d", &HH, &MM);
		isFirst = true, isFind = false;

		for (int i = HH; i <= 23; ++i) {

			for (int j = 0; j <= 59; ++j) {

				if (isFirst) { 
					
					j = MM, isFirst = false;
					continue; 
				}

				if (isPalindromic(i, j)) {
					
					cout << setfill('0') << setw(2) << i << ':' << setw(2) << j << '\n';
					isFind = true;
					break;
				}
			}
			
			if (isFind) { break; }
		}

		if (isFind) { continue; }

		for (int i = 0; i <= 23; ++i) {

			for (int j = 0; j <= 59; ++j) {

				if (isPalindromic(i, j)) {

					cout << setfill('0') << setw(2) << i << ':' << setw(2) << j << '\n';
					isFind = true;
					break;
				}
			}

			if (isFind) { break; }
		}
	}

	return 0;
}