#include <iostream>
#include <ctype.h>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	
	int i;
	char keyboard[] = { '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
						'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\',
						'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'',
						'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/' };
	string encodedMessage;

	getline(cin, encodedMessage);

	for (i = 0; i < encodedMessage.size(); i++) {

		char *pointer = find(keyboard, keyboard + 47, tolower(encodedMessage[i]));

		if (pointer != keyboard + 47) { printf("%c", *(pointer-2)); }
		else { printf("%c", encodedMessage[i]); }
	}

	printf("\n");

	return 0;
}