#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	struct shift { char down, up; };
	string line;
	unordered_map<int, struct shift> BAUDOT;

	getline(cin, line);
	for (int i = 0; i < 31; ++i) { BAUDOT[i].down = line[i]; }

	getline(cin, line);
	for (int i = 0; i < 31; ++i) { BAUDOT[i].up = line[i]; }

	while (cin >> line) {

		char status = 'D';

		for (int i = 0; i < line.size(); i += 5) {

			int bit = stoi(line.substr(i, 5), nullptr, 2);

			if (bit == 27) { status = 'D'; }
			else if (bit == 31) { status = 'U'; }
			else { status == 'D' ? cout << BAUDOT[bit].down : cout << BAUDOT[bit].up; }			
		}

		cout << endl;
	}

	return 0;
}