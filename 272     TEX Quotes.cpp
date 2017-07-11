#include <stdio.h>
#include <string.h>

int main() {

	char sen[10000];
	bool isFirst = true;

	while (gets(sen) != NULL) {
		
		for (int i = 0; i < strlen(sen); i++) {

			if (sen[i] != '\"') { printf("%c", sen[i]); }
			else {
								
				printf(isFirst == true ? "``" : "''");
				isFirst == true ? isFirst = false : isFirst = true;
			}			
		}

		printf("\n");
	}

	return 0;
}