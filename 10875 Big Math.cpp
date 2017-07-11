#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string line, digit;
	unordered_map<char, string> Math = { { '-', "......000......" },
										 { '0', "0000.00.00.0000" },
										 { '1', ".0..0..0..0..0." },
										 { '2', "000..00000..000" },
										 { '3', "000..0000..0000" },
										 { '4', "0.00.0000..0..0" },
										 { '5', "0000..000..0000" },
										 { '6', "0..0..0000.0000" },
										 { '7', "000..0..0..0..0" },
										 { '8', "0000.00000.0000" },
										 { '9', "0000.0000..0..0" } };

	while (getline(cin, line)) {

		long long int value = 0;
		stringstream ss(line);
		vector<string> Vec;
		vector<long long int> bufferA, bufferB;

		while (ss >> digit) { Vec.push_back(digit); }

		for (int i = 1; i < 5; ++i) {

			for (int j = 0; j < Vec.size(); ++j) {

				cin >> digit;
				Vec[j] += digit;
			}			
		}

		if (Vec.size() == 1 && Vec[0] == "0000.00.00.0000") { break; }

		for (int i = 0; i < Vec.size(); ++i) {
			
			if (Vec[i] == "0000.00.00.0000") { value *= 10; }
			else if (Vec[i] == ".0..0..0..0..0.") { value = value * 10 + 1; }
			else if (Vec[i] == "000..00000..000") { value = value * 10 + 2; }
			else if (Vec[i] == "000..0000..0000") { value = value * 10 + 3; }
			else if (Vec[i] == "0.00.0000..0..0") { value = value * 10 + 4; }
			else if (Vec[i] == "0000..000..0000") { value = value * 10 + 5; }
			else if (Vec[i] == "0..0..0000.0000") { value = value * 10 + 6; }
			else if (Vec[i] == "000..0..0..0..0") { value = value * 10 + 7; }
			else if (Vec[i] == "0000.00000.0000") { value = value * 10 + 8; }
			else if (Vec[i] == "0000.0000..0..0") { value = value * 10 + 9; }
			else if (Vec[i] == ".0..0.000.0..0.") { 
			
				bufferA.push_back(value);
				value = 0, bufferA.push_back(-1);
			}
			else if (Vec[i] == "......000......") {
			
				bufferA.push_back(value);
				value = 0, bufferA.push_back(-2);
			}
			else if (Vec[i] == "0.00.0.0.0.00.0") {
			
				bufferA.push_back(value);
				value = 0, bufferA.push_back(-3);
			}
			else if (Vec[i] == ".0....000....0.") {
			
				bufferA.push_back(value);
				value = 0, bufferA.push_back(-4);
			}
		}

		bufferA.push_back(value);

		for (int i = 0; i < bufferA.size(); ++i) {

			if (bufferA[i] == -3) {

				value = bufferB.back(), bufferB.pop_back();
				bufferB.push_back(value * bufferA[++i]);
			}
			else if (bufferA[i] == -4) {

				value = bufferB.back(), bufferB.pop_back();
				bufferB.push_back(value / bufferA[++i]);
			}
			else { bufferB.push_back(bufferA[i]); }
		}

		value = bufferB[0];

		for (int i = 1; i < bufferB.size(); ++i) {

			if (bufferB[i] == -1) { value += bufferB[++i]; }
			else if (bufferB[i] == -2) { value -= bufferB[++i]; }
		}

		line = to_string(value);

		for (int i = 0; i < 15; i += 3, cout << endl) {

			cout << Math[line[0]][i] << Math[line[0]][i + 1] << Math[line[0]][i + 2];

			for (int j = 1; j < line.size(); ++j) {

				cout << " " << Math[line[j]][i] << Math[line[j]][i + 1] << Math[line[j]][i + 2];
			}			
		}
		
		cout << endl;
		cin.ignore(), cin.ignore();
	}

	return 0;
}