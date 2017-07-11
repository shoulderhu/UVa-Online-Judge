#include <stdio.h>
#include <string.h>

int main() {

	int N;
	char sen[81];

	scanf("%d", &N), getchar();

	for (int i = 1; i <= N; i++) {

		scanf("%s", &sen), getchar();

		for (int j = 1; j <= strlen(sen); j++) {

			if (strlen(sen) % j == 0) {

				bool isPeriod = true;

				for (int k = j; k < strlen(sen); k++) {

					if (sen[k] != sen[k%j]) {

						isPeriod = false;
						break;
					}
				}

				if (isPeriod == true) {

					printf("%d\n", j);
					break;
				}
			}
		}

		if (i != N) { printf("\n"); }
	}
	
	return 0;
}
