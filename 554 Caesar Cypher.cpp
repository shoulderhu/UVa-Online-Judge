#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int max = 0, pos;
	string word, line, text;
	unordered_set<string> dictionary;
	unordered_map<int, char> de;
	unordered_map<char, int> en;

	de[0]  = ' ', de[1]  = 'A', de[2]  = 'B', de[3]  = 'C', de[4]  = 'D', de[5]  = 'E';
	de[6]  = 'F', de[7]  = 'G', de[8]  = 'H', de[9]  = 'I', de[10] = 'J', de[11] = 'K';
	de[12] = 'L', de[13] = 'M', de[14] = 'N', de[15] = 'O', de[16] = 'P', de[17] = 'Q';
	de[18] = 'R', de[19] = 'S', de[20] = 'T', de[21] = 'U', de[22] = 'V', de[23] = 'W';
	de[24] = 'X', de[25] = 'Y', de[26] = 'Z';

	en[' '] =  0, en['A'] =  1, en['B'] =  2, en['C'] =  3, en['D'] =  4, en['E'] =  5;
	en['F'] =  6, en['G'] =  7, en['H'] =  8, en['I'] =  9, en['J'] = 10, en['K'] = 11;
	en['L'] = 12, en['M'] = 13, en['N'] = 14, en['O'] = 15, en['P'] = 16, en['Q'] = 17;
	en['R'] = 18, en['S'] = 19, en['T'] = 20, en['U'] = 21, en['V'] = 22, en['W'] = 23;
	en['X'] = 24, en['Y'] = 25, en['Z'] = 26;

	while (cin >> word && word != "#") { dictionary.insert(word); }

	cin.ignore(1024, '\n'), getline(cin, line);

	for (int k = 1; k <= 26; ++k) {

		string lineCpy = line;

		for (int i = 0; i < lineCpy.size(); ++i) {

			int temp = en[lineCpy[i]];

			if (temp >= k) { lineCpy[i] = de[temp - k]; }
			else { lineCpy[i] = de[temp - k + 27]; }
		}

		int match = 0;
		stringstream ss(lineCpy);

		while (ss >> word) { if (dictionary.find(word) != dictionary.end()) { ++match; } }

		if (match > max) { max = match, text = lineCpy; }
	}

	while (text.size() > 60) {

		pos = 60;
		while (text[pos] != ' ') { --pos; }		

		cout << text.substr(0, pos) << endl;
		text.erase(0, pos + 1);
	}
	
	pos = text.size() - 1;
	while (text[pos] == ' ') { --pos; }
	cout << text.substr(0, pos + 1) << endl;

	return 0;
}