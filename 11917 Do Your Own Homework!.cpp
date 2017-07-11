#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, N, day, D, kace = 0;
	string subject, homework;
	
	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> N;

		map<string, int> table;

		for (int i = 1; i <= N; ++i) {

			cin >> subject >> day;
			table[subject] = day;
		}

		cin >> D >> homework;
		cout << "Case " << ++kace << ": ";
				
		if (table[homework] != 0 && table[homework] <= D) { cout << "Yesss\n"; }
		else if (table[homework] != 0 && table[homework] <= D + 5) { cout << "Late\n";}
		else { cout << "Do your own homework!\n"; }
	}

	return 0;
}