#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int Case, RAM[1000], REG[10], l;
	int unit, ten, hundred, instruction;
	bool isHalt;
	string content;
	
	cin >> Case, cin.ignore(), cin.ignore();

	for (int i = 0; i < Case; ++i) {

		if (i > 0) { cout << endl; }

		l = -1, instruction = 0, isHalt = false;
		memset(REG, 0, sizeof(REG));
		memset(RAM, 0, sizeof(RAM));

		while (getline(cin, content) && content != "") {
						
			RAM[++l] = stoi(content, nullptr, 10);
		}

		for (int j = 0; j < 1000 && !isHalt; ++j) {

			unit = RAM[j] % 10;
			ten = RAM[j] / 10 % 10;
			hundred = RAM[j] / 100;

			switch (hundred) {

			case 1:	if (ten == 0 && unit == 0) { isHalt = true; } break;
			case 2:	REG[ten] = unit; break;
			case 3:	REG[ten] += unit; break;
			case 4:	REG[ten] *= unit; break;
			case 5:	REG[ten] = REG[unit]; break;
			case 6: REG[ten] += REG[unit]; break;
			case 7:	REG[ten] *= REG[unit]; break;
			case 8:	REG[ten] = RAM[REG[unit]]; break;
			case 9:	RAM[REG[unit]] = REG[ten]; break;
			case 0:	if (REG[unit] != 0) { j = REG[ten] - 1; } break;
			}

			REG[ten] %= 1000;
			++instruction;
		}

		cout << instruction << endl;
	}

	return 0;
}