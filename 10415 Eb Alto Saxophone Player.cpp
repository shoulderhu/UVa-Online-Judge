#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

	unordered_map<char, string> note = { { 'c', "0111001111" },
	                                     { 'd', "0111001110" },
										 { 'e', "0111001100" },
										 { 'f', "0111001000" },
										 { 'g', "0111000000" },
										 { 'a', "0110000000" },
										 { 'b', "0100000000" },
										 { 'C', "0010000000" },
										 { 'D', "1111001110" },
										 { 'E', "1111001100" },
										 { 'F', "1111001000" },
										 { 'G', "1111000000" },
										 { 'A', "1110000000" },
										 { 'B', "1100000000" } };
		
	int t;
	string song;

	cin >> t, cin.ignore();

	for (int i = 0; i < t; ++i) {

		getline(cin, song);

		string buttom = "0000000000";
		vector<int> press(10, 0);

		for (int j = 0; j < song.size(); ++j) {

			for (int k = 0; k < 10; ++k) {

				if (buttom[k] == '0' && buttom[k] != note[song[j]][k]) {
					
					++press[k];
				}
			}

			buttom = note[song[j]];
		}

		for (int j = 0; j < 10; ++j) {

			cout << press[j];
			if (j != 9) { cout << " "; }
			else { cout << endl; }
		}
	}

	return 0;
}
