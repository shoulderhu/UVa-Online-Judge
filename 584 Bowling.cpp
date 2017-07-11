#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	char b;
	string line;

	while (getline(cin, line) && line != "Game Over") {

		int score = 0, game = 0;
		stringstream ss(line);
		vector<char> Bowling;

		while (ss >> b) { Bowling.push_back(b); }
		
		for (int i = 0; ++game != 11; ++i) {

			if (Bowling[i] == 'X') {

				score += 10;

				if (Bowling[i + 1] == 'X') { score += 10; }
				else if (Bowling[i + 2] == '/') { score += 10; continue; }
				else { score += Bowling[i + 1] - '0'; }

				if (Bowling[i + 2] == 'X') { score += 10; }				
				else { score += Bowling[i + 2] - '0'; }
			}
			else if (Bowling[i + 1] == '/') {

				score += 10;

				if (Bowling[i + 2] == 'X') { score += 10; }
				else { score += Bowling[i + 2] - '0'; }
				
				++i;
			}
			else { score += (Bowling[i] - '0') + (Bowling[i + 1] - '0'), ++i; }
		}

		cout << score << endl;
	}

	return 0;
}
