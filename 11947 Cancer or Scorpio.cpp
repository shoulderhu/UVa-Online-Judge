#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int N, MM, DD, YYYY;
int month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string format;
vector<pair<string, pair<int, int>>> sign = { { "aquarius", { 1, 21 } },
											  { "pisces", { 2, 20 } },
											  { "aries", { 3, 21 } },
											  { "taurus", { 4, 21 } },
											  { "gemini", { 5, 22 } },
											  { "cancer", { 6, 22 } },
											  { "leo", { 7, 23 } },
											  { "virgo", { 8, 22 } },
											  { "libra", { 9, 24 } },
											  { "scorpio", { 10, 24 } },
											  { "sagittarius", { 11, 23 } },
											  { "capricorn", { 12, 23 } } };

bool isLeapYear() {

	if ((YYYY % 4 == 0 && YYYY % 100 != 0) || YYYY % 400 == 0) {

		return true;
	}
	else { return false; }
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; ++i) {

		bool isFound = false;

		cin >> format;
		MM = stoi(format.substr(0, 2), nullptr, 10);
		DD = stoi(format.substr(2, 2), nullptr, 10) + 280;
		YYYY = stoi(format.substr(4, 4), nullptr, 10);
		month[2] = isLeapYear() ? 29 : 28;		

		for (int j = MM; ; ++j) {

			if (j == 13) { 
				
				j = 1, ++YYYY;
				month[2] = isLeapYear() ? 29 : 28;
			}

			if (DD > month[j]) { DD -= month[j]; }
			else {

				cout << i << " " << setw(2) << setfill('0') << j << "/"
					             << setw(2) << setfill('0') << DD << "/"
					             << YYYY << " ";

				for (auto iter = sign.rbegin(); iter != sign.rend(); ++iter) {
					
					if (j > iter->second.first ||
						(j == iter->second.first && DD >= iter->second.second)) {

						isFound = true;
						cout << iter->first << endl;
						break;
					}					
				}

				if (isFound == false) { cout << "capricorn" << endl; }

				break;
			}
		}
	}

	return 0;
}