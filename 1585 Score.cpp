#include <stdio.h>
#include <string.h>

using namespace std;

int main() {

	int T;
	char testResult[81];
	
	scanf("%d", &T), getchar();

	for (int i = 1; i <= T; i++) {

		scanf("%s", &testResult), getchar();
		
		int score = 0;
		char * subStr = strtok(testResult, "X");

		while (subStr != NULL) {

			int temp = strlen(subStr);

			score += (temp + 1)*temp / 2;
			subStr = strtok(NULL, "X");
		}
		
		printf("%d\n", score);
	}

	return 0;
}
