#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int cases, X;

	cin >> cases;

	for (int i = 1; i <= cases; ++i) {

		int Y = 0;
		vector<string> deck(27), hand(25);

		for (int j = 0; j < 27; ++j) { cin >> deck[j]; }
		for (int j = 0; j < 25; ++j) { cin >> hand[j]; }
		
		for (int j = 0; j < 3; ++j) {
			
			if (isdigit(deck.back()[0]) != 0) { X = deck.back()[0] - '0'; }
			else { X = 10; }

			Y += X, deck.pop_back(), X = 10 - X;
			for (int k = 0; k < X; ++k) { deck.pop_back(); }
		}

		deck.insert(deck.end(), hand.begin(), hand.end());
		cout << "Case " << i << ": " << deck[Y - 1] << endl;
	}

	return 0;
}