#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace, n, order;
	struct card { string f, s; };
	string K, suit[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
	string face[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
		
	cin >> kace, cin.ignore(), cin.ignore();

	for (int i = 0; i < kace; ++i) {

		if (i > 0) { cout << endl; }

		cin >> n, cin.ignore();

		int pos = -1;
		struct card Card[52], stack[52];
		vector<vector<int>> Vec(n);

		for (int i = 0; i < 4; ++i) {

			for (int j = 0; j < 13; ++j) {

				Card[++pos].s = suit[i], Card[pos].f = face[j];
			}
		}
				
		for (int j = 0; j < n; ++j) {

			for (int k = 0; k < 52; ++k) {

				cin >> order;
				Vec[j].push_back(order);
			}			
		}
				
		cin.ignore(1024, '\n');

		while (getline(cin, K) && K != "") {

			int k = stoi(K, nullptr, 10) - 1;

			for (int j = 0; j < 52; ++j) {

				stack[j] = Card[Vec[k][j] - 1];
			}

			swap(stack, Card);
		}

		for (int j = 0; j < 52; ++j) {

			cout << Card[j].f << " of " << Card[j].s << endl;
		}
	}

	return 0;
}