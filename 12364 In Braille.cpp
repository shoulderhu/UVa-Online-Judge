#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int D;
	char letter;
	string message;
	unordered_map<char, string> S = { { '0', ".***.." }, { '1', "*....." },
									  { '2', "*.*..." }, { '3', "**...." },
									  { '4', "**.*.." }, { '5', "*..*.." },
									  { '6', "***..." }, { '7', "****.." },
									  { '8', "*.**.." }, { '9', ".**..." } };
	unordered_map<string, char> B = { { ".***..", '0' }, { "*.....", '1' },
	                                  { "*.*...", '2' }, { "**....", '3' },
	                                  { "**.*..", '4' }, { "*..*..", '5' },
	                                  { "***...", '6' }, { "****..", '7' },
	                                  { "*.**..", '8' }, { ".**...", '9' } };

	while (cin >> D && D != 0) {

		cin >> letter;

		if (letter == 'S') {

			cin >> message;

			for (int j = 0; j < 6; j += 2, cout << endl) {

				cout << S[message[0]][j] << S[message[0]][j + 1];

				for (int k = 1; k < D; ++k) {

					cout << " " << S[message[k]][j] << S[message[k]][j + 1];
				}
			}			
		}
		else {

			vector<string> Braille(D);

			for (int i = 0; i < 3; ++i) {

				for (int j = 0; j < D; ++j) {

					cin >> message;
					Braille[j] += message;
				}
			}

			for (int i = 0; i < Braille.size(); ++i) { cout << B[Braille[i]]; }
			cout << endl;
		}
	}

	return 0;
}