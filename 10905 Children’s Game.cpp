#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

inline bool mySort(string a, string b) { return a + b > b + a; }

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	string input;
	vector<string> game;

	while (cin >> N && N != 0) {

		game.clear();

		for (int i = 1; i <= N; i++) {

			cin >> input;
			game.push_back(input);
		}

		sort(game.begin(), game.end(), mySort);

		for (int i = 0; i < game.size(); i++) { cout << game[i]; }

		cout << endl;
	}

	return 0;
}
