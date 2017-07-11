#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int cases = 0;
	long long int num;
	string text[] = { "kuti", "lakh", "hajar", "shata" };

	while (cin >> num) {

		int left = num % 100, pos = 3;
		vector<pair<int, string>> Bangla;
		
		cout << setw(4) << ++cases << ".";

		if (num == 0) { cout << " 0" << endl; continue; }
		num /= 100;		

		while (num != 0) {

			if (pos == 3) {

				Bangla.push_back({ num % 10, text[pos] });
				num /= 10;
			}
			else {

				Bangla.push_back({ num % 100, text[pos] });
				num /= 100;
			}
			
			if (--pos == -1) { pos = 3; }
		}
		
		for (auto iter = Bangla.rbegin(); iter != Bangla.rend(); ++iter) {

			if (iter->first == 0) { 
				
				if (iter->second == "kuti") { cout << " kuti"; }
			}
			else { cout << " " << iter->first << " " << iter->second; }
		}

		if (left != 0) { cout << " " << left; }
		cout << endl;		
	}

	return 0;
}