#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	struct pilot {

		int X, Y, Z;
		string S;		
	}Pilot;
	string colon, min, sec, ms;	

	while (cin >> N) {
		
		int row = 0;
		vector<struct pilot> Vec;

		for (int i = 0; i < N; ++i) {

			cin >> Pilot.S >> colon >> Pilot.X >> min >> Pilot.Y >> sec >> Pilot.Z >> ms;
			Vec.push_back(Pilot);
		}

		sort(Vec.begin(), Vec.end(), [](struct pilot a, struct pilot b) {
		
			if (a.X != b.X) { return a.X < b.X; }
			else if (a.Y != b.Y) { return a.Y < b.Y; }
			else if (a.Z != b.Z) { return a.Z < b.Z; }
			else {

				string s[] = { a.S, b.S };

				for (int i = 0; i < 2; ++i) {
					
					transform(s[i].begin(), s[i].end(), s[i].begin(), ::tolower);
				}
				
				return s[0] < s[1];
			}
		});

		for (int i = 0; i < Vec.size(); ++i) {
			
			cout << "Row " << ++row << endl;

			if (i + 1 < Vec.size()) {

				cout << Vec[i].S << endl;
				cout << Vec[i + 1].S << endl;
				++i;
			}
			else { cout << Vec[i].S << endl; }
		}

		cout << endl;
	}

	return 0;
}