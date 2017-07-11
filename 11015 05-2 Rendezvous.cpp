#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, I, J, K, Map[23][23], kace = 0;
	string name;
	
	while (cin >> N >> M && N != 0) {
		
		int minCost = 21001, place;
		vector<string> Vector;
		set<int> Set;

		for (int i = 1; i < 23; ++i) {

			for (int j = 1; j < 23; ++j) { Map[i][j] = 21001; }
			Map[i][i] = 0;
		}

		for (int i = 1; i <= N; ++i) {

			cin >> name;
			Vector.push_back(name);
		}

		for (int i = 1; i <= M; ++i) {

			cin >> I >> J >> K;
			Set.insert(I), Set.insert(J);
			Map[I][J] = K, Map[J][I] = K;
		}
				
		for (auto iter = Set.begin(); iter != Set.end(); ++iter) {

			for (auto jter = Set.begin(); jter != Set.end(); ++jter) {

				for (auto kter = Set.begin(); kter != Set.end(); ++kter) {

					Map[*jter][*kter] = min(Map[*jter][*kter], 
						                    Map[*jter][*iter] + Map[*iter][*kter]);
				}
			}
		}

		for (int i = 1; i <= N; ++i) {

			int cost = 0;

			for (int j = 1; j <= N; ++j) { cost += Map[j][i]; }
			if (minCost > cost) { minCost = cost, place = i; }
		}

		cout << "Case #" << ++kace << " : " << Vector[place - 1] << endl;			
	}
	
	return 0;
}