#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, M, status[] = { 56, 51, 41, 36 };
	string face, suit, of;

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		if (i > 1) { cout << endl; }

		cin >> M;

		int ouler = 0;
		double point = 0;

		for (int j = 0; j < M; ++j) {

			cin >> face;

			if (face == "fool") { ++ouler, point += 4.5; }
			else {

				cin >> of >> suit;

				if (face == "king") { point += 4.5; }
				else if (face == "queen") { point += 3.5; }
				else if (face == "knight") { point += 2.5; }
				else if (face == "jack") { point += 1.5; }
				else if (suit == "trumps" && face == "one" || face == "twenty-one") {

					++ouler, point += 4.5;					
				}
				else{ point += 0.5; }
			}
		}

		cout << "Hand #" << i << endl;
		
		if (point >= status[ouler]) { 
			
			cout << "Game won by " << point - status[ouler] << " point(s)." << endl;;
		}
		else { cout << "Game lost by " << status[ouler] - point << " point(s)." << endl; }
	}

	return 0;
}