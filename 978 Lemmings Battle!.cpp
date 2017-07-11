#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, SG, SB, s;
	size_t B;
	priority_queue<int> Green, Blue;
	
	cin >> N;
	
	for (int i = 1; i <= N; ++i) {

		if (i > 1) { cout << endl; }

		cin >> B >> SG >> SB;

		for(int j = 1; j<=SG; ++j){
			
			cin >> s;
			Green.push(s);
		}

		for (int j = 1; j <= SB; ++j) {

			cin >> s;
			Blue.push(s);
		}

		while (Green.empty() == false && Blue.empty() == false) {

			vector<int> tempG, tempB;
			B = min(B, Green.size()), B = min(B, Blue.size());
			
			for (int j = 1; j <= B; ++j) {

				int g = Green.top(), b = Blue.top();
				Green.pop(), Blue.pop();

				if (g > b) { tempG.push_back(g - b); }
				else if (b > g) { tempB.push_back(b - g); }
			}

			for (int j = 0; j < tempG.size(); ++j) { Green.push(tempG[j]); }
			for (int j = 0; j < tempB.size(); ++j) { Blue.push(tempB[j]); }
		}

		if (Green.empty() == true) {
		
			if (Blue.empty() == true) { cout << "green and blue died" << endl; }
			else {

				cout << "blue wins" << endl;

				do {
					cout << Blue.top() << endl;
					Blue.pop();

				} while (Blue.empty() == false);				
			}
		}
		else {

			cout << "green wins" << endl;

			do {
				cout << Green.top() << endl;
				Green.pop();

			} while (Green.empty() == false);
		}
	}

	return 0;
}