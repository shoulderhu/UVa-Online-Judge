#include <iostream>
#include <cctype>
#include <map>

using namespace std;

int main() {

	int i;
	char input;
	map<char, int> telephone;

	for (i = 'A'; i <= 'Z'; i++) {

		if (i == 'A' || i == 'B' || i == 'C') { telephone[i] = 2; }
		else if (i == 'D' || i == 'E' || i == 'F') { telephone[i] = 3; }
		else if (i == 'G' || i == 'H' || i == 'I') { telephone[i] = 4; }
		else if (i == 'J' || i == 'K' || i == 'L') { telephone[i] = 5; }
		else if (i == 'M' || i == 'N' || i == 'O') { telephone[i] = 6; }
		else if (i == 'P' || i == 'Q' || i == 'R' || i == 'S') { telephone[i] = 7; }
		else if (i == 'T' || i == 'U' || i == 'V') { telephone[i] = 8; }
		else if (i == 'W' || i == 'X' || i == 'Y' || i == 'Z') { telephone[i] = 9; }
	}

	while ((input = getchar()) != EOF) {

		if (isalpha(input) != 0) {

			printf("%d", telephone[input]);
		}
		else { printf("%c", input); }
	}

	return 0;
}