#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace, a, b, c, from, to, roll;

	cin >> kace;

	for (int i = 0; i < kace; ++i) {

		cin >> a >> b >> c;

		int pos = 0;
		bool isWon = false;
		vector<int> position(a, 1);
		unordered_map<int, int> Map;

		for (int j = 0; j < b; ++j) {

			cin >> from >> to;
			Map[from] = to;
		}

		for (int j = 0; j < c; ++j) {

			cin >> roll;
			
			if (isWon == false) {

				position[pos] += roll;

				if (Map.find(position[pos]) != Map.end()) {

					position[pos] = Map[position[pos]];
				}

				if (position[pos] >= 100) { 
					
					position[pos] = 100;
					isWon = true;
					continue; 
				}
				
				if (++pos == a) { pos = 0; }				
			}						
		}

		for (int i = 0; i < position.size(); ++i) {

			cout << "Position of player " << i + 1 << " is " << position[i] << "." << endl;
		}
	}
	
	return 0;
}