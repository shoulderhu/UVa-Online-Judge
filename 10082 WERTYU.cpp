#include <stdio.h>
#include <string.h>

int main() {
		
	char sen[10000];
	char keys[] = { '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
					'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\',
					'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'',
					'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/' };
	
	while (gets_s(sen)!=NULL) {

		for (int i = 0; i < strlen(sen); i++) {

			bool isPrint = false;

			for (int j = 0; j < 47; j++) {

				if (sen[i] == keys[j]) { 
					
					printf("%c", keys[j - 1]); 
					isPrint = true;
					break;
				}
			}

			if (isPrint != true) { printf("%c", sen[i]); }
		}

		printf("\n");
	}

	return 0;
}