#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, message = 0;
	size_t pos;
	string line, code;
	map<string, char> Morse;

	Morse[".-"]     = 'A', Morse["-..."]   = 'B', Morse["-.-."]   = 'C',
	Morse["-.."]    = 'D', Morse["."]      = 'E', Morse["..-."]   = 'F', 
	Morse["--."]    = 'G', Morse["...."]   = 'H', Morse[".."]     = 'I',
	Morse[".---"]   = 'J', Morse["-.-"]    = 'K', Morse[".-.."]   = 'L',
	Morse["--"]     = 'M', Morse["-."]     = 'N', Morse["---"]    = 'O', 
	Morse[".--."]   = 'P', Morse["--.-"]   = 'Q', Morse[".-."]    = 'R', 
	Morse["..."]    = 'S', Morse["-"]      = 'T', Morse["..-"]    = 'U', 
	Morse["...-"]   = 'V', Morse[".--"]    = 'W', Morse["-..-"]   = 'X',
	Morse["-.--"]   = 'Y', Morse["--.."]   = 'Z', Morse["-----"]  = '0', 
	Morse[".----"]  = '1',  Morse["..---"] = '2', Morse["...--"]  = '3', 
	Morse["....-"]  = '4', Morse["....."]  = '5', Morse["-...."]  = '6', 
	Morse["--..."]  = '7', Morse["---.."]  = '8', Morse["----."]  = '9',
	Morse[".-.-.-"] = '.', Morse["--..--"] = ',', Morse["..--.."] = '?',
	Morse[".----."] = '\'', Morse["-.-.--"] = '!', Morse["-..-."]  = '/',
	Morse["-.--."]  = '(', Morse["-.--.-"] = ')', Morse[".-..."]  = '&',
	Morse["---..."] = ':', Morse["-.-.-."] = ';', Morse["-...-"]  = '=',
	Morse[".-.-."]  = '+', Morse["-....-"] = '-', Morse["..--.-"] = '_',
	Morse[".-..-."] = '"', Morse[".--.-."] = '@', Morse["_"] = ' ';

	cin >> T, cin.ignore();

	for (int i = 1; i <= T; ++i) {

		if (i > 1) { cout << endl; }

		getline(cin, line);
		while ((pos = line.find("  ")) != string::npos) { line.insert(pos + 1, "_"); }

		stringstream ss(line);

		cout << "Message #" << ++message << endl;
		while (ss >> code) { cout << Morse[code]; }
		cout << endl;
	}

	return 0;
}