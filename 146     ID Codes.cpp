#include <stdio.h>
#include <string.h>
#include <algorithm>

int main() {

	char ID[51];

	while (scanf("%s", &ID) != EOF) {

		getchar();

		if (ID[0] == '#') { break; }

		if (std::next_permutation(ID, ID+strlen(ID)) == true) {

			for (int i = 0; i < strlen(ID); i++) { printf("%c", ID[i]); }
			printf("\n");
		}
		else { printf("No Successor\n"); }
	}

	return 0;
}