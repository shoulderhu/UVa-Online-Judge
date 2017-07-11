#include <iostream>
#include <cctype>
#include <string>
#include <map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int dataset, number;
	size_t pos;
	string line;
	map<char, char> keypad = { { 'A', '2' }, { 'B', '2' }, { 'C', '2' },
							   { 'D', '3' }, { 'E', '3' }, { 'F', '3' }, 
							   { 'G', '4' }, { 'H', '4' }, { 'I', '4' },
							   { 'J', '5' }, { 'K', '5' }, { 'L', '5' }, 
							   { 'M', '6' }, { 'N', '6' }, { 'O', '6' },
							   { 'P', '7' }, { 'R', '7' }, { 'S', '7' }, 
							   { 'T', '8' }, { 'U', '8' }, { 'V', '8' }, 
							   { 'W', '9' }, { 'X', '9' }, { 'Y', '9' } };
	cin >> dataset;

	for (int i = 1; i <= dataset; ++i) {

		if (i > 1) { cout << endl; }

		cin >> number;

		bool isPrint = false;
		map<string, int> telephone;

		for (int j = 1; j <= number; ++j) {

			cin >> line;

			while ((pos = line.find('-')) != string::npos) { line.erase(pos, 1); }

			for (int k = 0; k < line.size(); ++k) {

				if (isalpha(line[k]) != 0) { line[k] = keypad[line[k]]; }
			}

			line.insert(3, "-"), ++telephone[line];
		}

		for (auto iter = telephone.begin(); iter != telephone.end(); ++iter) {

			if (iter->second > 1) { 
				
				isPrint = true;
				cout << iter->first << " " << iter->second << endl;
			}
		}

		if (isPrint == false) { cout << "No duplicates." << endl; }
	}

	return 0;
}