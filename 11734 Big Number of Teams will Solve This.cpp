#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, kace = 0;	
	string team, judge;

	cin >> t, cin.ignore();

	for (int i = 1; i <= t; ++i) {

		getline(cin, team);
		getline(cin, judge);

		cout << "Case " << ++kace << ": ";

		if (team == judge) { cout << "Yes" << endl; }
		else {
						
			for (auto iter = team.begin(); iter!=team.end(); ) {

				if (*iter == ' ') { iter = team.erase(iter); }
				else { ++iter; }
			}

			if (team == judge) { cout << "Output Format Error" << endl; }
			else { cout << "Wrong Answer" << endl; }
		}
	}

	return 0;
}