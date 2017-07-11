#include <stdio.h>
#include <string.h>

int main() {

	char equation[100];

	while (gets(equation) != NULL) {

		for (int i = 0; i < strlen(equation); i++) { printf("%c", equation[i]); }
		printf("\n");
	}

	return 0;
}