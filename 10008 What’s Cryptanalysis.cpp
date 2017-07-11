#include <iostream>
#include <string>
#include <ctype.h>
#include <map>

using namespace std;

int main() {

	int i, j, n, max = 0;
	string line;
	map<char, int> letter;

	scanf("%d", &n), getchar();
	
	for (i = 1; i <= n; i++) {

		getline(cin, line);

		for (j = 0; j < line.size(); j++) {

			if (isalpha(line[j]) != 0) {

				letter[toupper(line[j])]++;

				if (letter[toupper(line[j])]>max) { max = letter[toupper(line[j])]; }
			}
		}
	}

	for (i = max; i >= 1; i--) {

		for (j = 'A'; j <= 'Z'; j++) {

			if (letter[j] == i) { printf("%c %d\n", j, letter[j]); }
		}
	}

	return 0;
}
