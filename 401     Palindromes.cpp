#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

	int i;
	string input;
	map<char, char> reverse;
	
	reverse['A'] = 'A', reverse['E'] = '3', reverse['H'] = 'H',
	reverse['I'] = 'I', reverse['J'] = 'L', reverse['L'] = 'J',
	reverse['M'] = 'M', reverse['O'] = 'O', reverse['S'] = '2', 
	reverse['T'] = 'T', reverse['U'] = 'U', reverse['V'] = 'V',
	reverse['W'] = 'W', reverse['X'] = 'X', reverse['Y'] = 'Y',
	reverse['Z'] = '5', reverse['1'] = '1', reverse['2'] = 'S',
	reverse['3'] = 'E', reverse['5'] = 'Z', reverse['8'] = '8';

	while (cin >> input) {
				
		bool isPalindrome = true, isMirrored = true;
		string mirrorInput = "";

		for (i = 0; i < input.size() / 2; i++) {

			if (input[i] != input[input.size() - 1 - i]) {

				isPalindrome = false;
				break;
			}
		}

		for (i = 0; i < input.size(); i++) {

			if (reverse.find(input[i]) != reverse.end()) { 
				
				mirrorInput += reverse[input[i]];
			}
		}

		if (input.size() != mirrorInput.size()) { isMirrored = false; }
		else {

			for (i = 0; i < input.size(); i++) {

				if (input[i] != mirrorInput[mirrorInput.size() - 1 - i]) {

					isMirrored = false;
					break;
				}
			}
		}
		

		if (isPalindrome == true && isMirrored == true) {

			printf("%s -- is a mirrored palindrome.\n", input.c_str());
		}
		else if (isPalindrome == true) {

			printf("%s -- is a regular palindrome.\n", input.c_str());
		}
		else if (isMirrored == true) {

			printf("%s -- is a mirrored string.\n", input.c_str());
		}
		else { printf("%s -- is not a palindrome.\n", input.c_str()); }

		printf("\n");
	}

	return 0;
}