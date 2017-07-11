#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N = 0, C, CoH[2][26][26], f;
	char first, second, third, forth, me, Prof;
	map<char, int> Map;

	for (int i = 'A'; i <= 'Z'; ++i, ++N) { Map[i] = N; }

	while (cin >> N && N != 0) {

		int minEnergy = 12501;
		set<int> Set[2], place;
		
		for (int i = 0; i < 26; ++i) {

			for (int j = 0; j < 26; ++j) { CoH[0][i][j] = 12501, CoH[1][i][j] = 12501; }
			CoH[0][i][i] = 0, CoH[1][i][i] = 0;
		}

		for (int i = 1; i <= N; ++i) {

			cin >> first >> second >> third >> forth >> C;

			f = (first == 'Y' ? 0 : 1);
			CoH[f][Map[third]][Map[forth]] = min(CoH[f][Map[third]][Map[forth]], C);
			Set[f].insert(Map[third]), Set[f].insert(Map[forth]);
			if (second == 'B') { CoH[f][Map[forth]][Map[third]] = min(CoH[f][Map[forth]][Map[third]], C); }		
		}
		
		for (int j = 0; j < 2; ++j) {
		
			for (auto iter = Set[j].begin(); iter != Set[j].end(); ++iter) {
			
				for (auto jter = Set[j].begin(); jter != Set[j].end(); ++jter) {
				
					for (auto kter = Set[j].begin(); kter != Set[j].end(); ++kter) {

						CoH[j][*jter][*kter] = min(CoH[j][*jter][*kter], 
							                       CoH[j][*jter][*iter] + CoH[j][*iter][*kter]);
					}
				}
			}
		}
		
		cin >> me >> Prof;

		for (int i = 0; i < 26; ++i) {

			int energy = CoH[0][Map[me]][i] + CoH[1][Map[Prof]][i];

			if (minEnergy > energy) {

				minEnergy = energy;
				place.clear(), place.insert(i);
			}
			else if (minEnergy == energy) { place.insert(i); }
		}
								
		if (minEnergy == 12501) { cout << "You will never meet." << endl; }
		else {

			cout << minEnergy << " " << (char)(*place.begin() + 65);

			for (auto iter = ++place.begin(); iter != place.end(); ++iter) {

				cout << " " << (char)(*iter + 65);
			}

			cout << endl;
		}		
	}

	return 0;
}