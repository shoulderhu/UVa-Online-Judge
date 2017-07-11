#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string line;
	map<char, char> key;

	key['4'] = 'q', key['5'] = 'j', key['6'] = 'l', key['7'] = 'm', key['8'] = 'f',
	key['9'] = 'p', key['0'] = '/', key['-'] = '[', key['='] = ']', key['q'] = '4',
	key['w'] = '5', key['e'] = '6', key['r'] = '.', key['t'] = 'o', key['y'] = 'r',
	key['u'] = 's', key['i'] = 'u', key['o'] = 'y', key['p'] = 'b', key['['] = ';',
	key[']'] = '=', key['a'] = '7', key['s'] = '8', key['d'] = '9', key['f'] = 'a',
	key['g'] = 'e', key['j'] = 't', key['k'] = 'd', key['l'] = 'c', key[';'] = 'k',
	key['\''] = '-', key['z'] = '0', key['x'] = 'z', key['c'] = 'x', key['v'] = ',',
	key['b'] = 'i', key['n'] = 'n', key['m'] = 'w', key[','] = 'v', key['.'] = 'g',
	key['/'] = '\'', key['$'] = 'Q', key['%'] = 'J', key['^'] = 'L', key['&'] = 'M',
	key['*'] = 'F', key['('] = 'P', key[')'] = '?', key['_'] = '{', key['+'] = '}',
	key['Q'] = '$', key['W'] = '%', key['E'] = '^', key['R'] = '>', key['T'] = 'O',
	key['Y'] = 'R', key['U'] = 'S', key['I'] = 'U', key['O'] = 'Y', key['P'] = 'B',
	key['{'] = ':', key['}'] = '+', key['A'] = '&', key['S'] = '*', key['D'] = '(',
	key['F'] = 'A', key['G'] = 'E', key['H'] = 'H', key['J'] = 'T', key['K'] = 'D',
	key['L'] = 'C', key[':'] = 'K', key['\"'] = '_', key['Z'] = ')', key['X'] = 'Z',
	key['C'] = 'X', key['V'] = '<', key['B'] = 'I', key['M'] = 'W', key['<'] = 'V',
	key['>'] = 'G', key['?'] = '\"';

	while (getline(cin, line)) {

		for (int i = 0; i < line.size(); ++i) {

			if (key.find(line[i]) != key.end()) { cout << key[line[i]]; }
			else { cout << line[i]; }
		}

		cout << endl;
	}

	return 0;
}