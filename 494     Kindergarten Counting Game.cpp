#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

	int i;
	char line[10000];

	while (gets(line) != NULL) {

		int words = 0;

		for (i = 0; i < strlen(line); i++) {

			if (isalpha(line[i]) != 0) {

				words++;
				while (isalpha(line[i + 1]) != 0) { i++; }
			}			
		}

		printf("%d\n", words);
	}

	return 0;
}
