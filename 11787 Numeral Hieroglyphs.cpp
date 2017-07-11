#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<char, int> hieroglyph;
inline bool mySort1(char &a, char &b) { return hieroglyph[a] < hieroglyph[b]; }
inline bool mySort2(char &a, char &b) { return hieroglyph[a] > hieroglyph[b]; }

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace;
	string line;
	
	hieroglyph['B'] = 1, hieroglyph['U'] = 2, hieroglyph['S'] = 3, hieroglyph['P'] = 4;
	hieroglyph['F'] = 5, hieroglyph['T'] = 6, hieroglyph['M'] = 7;

	cin >> kace;

	for (int i = 0; i < kace; ++i) {

		cin >> line;

		if (is_sorted(line.begin(), line.end(), mySort1) == false && 
			is_sorted(line.begin(), line.end(), mySort2) == false) {

			cout << "error" << endl;
			continue;
		}

		int sum = 0;
		bool isError = false;
		unordered_map<char, int> Map;

		for (int j = 0; j < line.size(); ++j) {
			
			if (++Map[line[j]] > 9) {
			
				cout << "error" << endl;
				isError = true;
				break;
			}
			else {

				switch (line[j]) {
				
				case 'B': ++sum; break;
				case 'U': sum += 10; break;
				case 'S': sum += 100; break;
				case 'P': sum += 1000; break;
				case 'F': sum += 10000; break;
				case 'T': sum += 100000; break;
				case 'M': sum += 1000000; break;
				}
			}
		}

		if (isError == false) { cout << sum << endl; }
	}

	return 0;
}