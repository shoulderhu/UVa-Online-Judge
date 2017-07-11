#include <stdio.h>
#include <string.h>

int main() {

	int i;
	char word[20];	

	while (scanf("%s", &word) != EOF) {

		getchar();
		
		for (i = 0; i < strlen(word); i++) {

			switch (word[i]) {

			case 'B': case 'F': case 'P': case 'V':

				printf("1");
				while (word[i + 1] == 'B' || word[i + 1] == 'F' || word[i + 1] == 'P' || word[i + 1] == 'V') { i++; }

				break;
			case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z':

				printf("2");
				while (word[i + 1] == 'C' || word[i + 1] == 'G' || word[i + 1] == 'J' || word[i + 1] == 'K' || word[i + 1] == 'Q' || word[i + 1] == 'S' || word[i + 1] == 'X' || word[i + 1] == 'Z') { i++; }

				break;
			case 'D': case 'T':

				printf("3");
				while (word[i + 1] == 'D' || word[i + 1] == 'T') { i++; }

				break;
			case 'L':

				printf("4");
				while (word[i + 1] == 'L') { i++; }

				break;
			case 'M': case 'N':

				printf("5");
				while (word[i + 1] == 'M' || word[i + 1] == 'N') { i++; }

				break;
			case 'R':

				printf("6");
				while (word[i + 1] == 'R') { i++; }

				break;
			}
		}

		printf("\n");
	}

	return 0;
}