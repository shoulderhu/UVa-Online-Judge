#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	string line;

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> line;
		
		int pointer = 0;
		vector<int> Memory(100, 0);

		for (int j = 0; j < line.size(); ++j) {

			switch (line[j]) {

			case '>': if (++pointer == 100) { pointer = 0; }; break;
			case '<': if (--pointer == -1) { pointer = 99; } break;
			case '+': if (++Memory[pointer] == 256) { Memory[pointer] = 0; }; break;
			case '-': if (--Memory[pointer] == -1) { Memory[pointer] = 255; }; break;
			}			
		}

		cout << "Case " << dec << i << ":";

		for (int j = 0; j < 100; ++j) { 
			
			cout << " " << setw(2) << setfill('0') << hex << uppercase << Memory[j];			
		}

		cout << endl;
	}

	return 0;
}