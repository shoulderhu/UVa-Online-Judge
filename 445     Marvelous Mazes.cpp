#include <stdio.h>
#include <ctype.h>

int main() {

	int i, times = 0;
	char input;

	while ((input = getchar()) != EOF) {
	
		if (isdigit(input) != 0) { times += input - '0'; }
		else if (isalpha(input) != 0 || input=='*') {

			if (input == 'b') { for (i = 1; i <= times; i++) { printf(" "); } }
			else { for (i = 1; i <= times; i++) { printf("%c", input); } }
			times = 0;
		}
		else if (input == '!') { printf("\n"); }	
		else if (input == '\n') { printf("\n"); }
	}

	return 0;
}