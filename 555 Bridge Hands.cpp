#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<char, int> MAP = { {'C', 1}, {'D', 2}, {'S', 3}, {'H', 4},
								 {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5},
								 {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
								 {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14} };

bool mySort(string a, string b) {

	if (a[0] != b[0]) { return MAP[a[0]] < MAP[b[0]]; }
	else { return MAP[a[1]] < MAP[b[1]]; }
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	char dealer;
	string line, card;
	unordered_map<char, char> Map = { {'N', 'E'}, {'E', 'S'}, {'S', 'W'}, {'W', 'N'} };
	
	while (cin >> dealer && dealer != '#') {

		dealer = Map[dealer];
		vector<string> S, W, N, E;

		for (int i = 0; i < 2; ++i) {

			cin >> line;

			for (int j = 0; j < 52; j += 2) {

				switch (dealer) {

				case 'S': S.push_back(line.substr(j, 2)); break;
				case 'W': W.push_back(line.substr(j, 2)); break;
				case 'N': N.push_back(line.substr(j, 2)); break;
				case 'E': E.push_back(line.substr(j, 2)); break;
				}

				dealer = Map[dealer];
			}
		}

		sort(S.begin(), S.end(), mySort);
		sort(W.begin(), W.end(), mySort);
		sort(N.begin(), N.end(), mySort);
		sort(E.begin(), E.end(), mySort);

		cout << "S:";
		for (auto iter = S.begin(); iter != S.end(); ++iter) { cout << " " << *iter; }
		cout << endl;

		cout << "W:";
		for (auto iter = W.begin(); iter != W.end(); ++iter) { cout << " " << *iter; }
		cout << endl;

		cout << "N:";
		for (auto iter = N.begin(); iter != N.end(); ++iter) { cout << " " << *iter; }
		cout << endl;

		cout << "E:";
		for (auto iter = E.begin(); iter != E.end(); ++iter) { cout << " " << *iter; }
		cout << endl;
	}	

	return 0;
}