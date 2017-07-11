#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string name;
	unordered_map<char, int> Map;

	Map['B'] = 1, Map['P'] = 1, Map['F'] = 1, Map['V'] = 1, Map['C'] = 2;
	Map['S'] = 2, Map['K'] = 2, Map['G'] = 2, Map['J'] = 2, Map['Q'] = 2;
	Map['X'] = 2, Map['Z'] = 2, Map['D'] = 3, Map['T'] = 3, Map['L'] = 4;
	Map['M'] = 5, Map['N'] = 5, Map['R'] = 6;

	cout << "         NAME                     SOUNDEX CODE" << endl;

	while(cin >> name) {
				
		int digit = 0;

		cout << "         " << setw(25) << left << name << name[0];

		for (int i = 1; i < name.size() && digit != 3; ++i) {

			if (name[i] != 'A' && name[i] != 'E' && name[i] != 'I' && name[i] != 'O' &&
				name[i] != 'U' && name[i] != 'Y' && name[i] != 'W' && name[i] != 'H') {

				if (Map[name[i]] != Map[name[i - 1]]) {

					cout << Map[name[i]];
					++digit;
				}
			}
		}

		if (digit != 3) { for (int i = digit; i < 3; ++i) { cout << "0"; } }

		cout << endl;
	}

	cout << "                   END OF OUTPUT" << endl;

	return 0;
}