#include <stdio.h>
#include <string.h>

using namespace std;

int main() {

	int i, j, N, x = 0;
	char sen[99][101];

	while (scanf("%d", &N) != EOF && N != 0) {
		
		getchar();

		for (i = 0; i < N; i++) { gets(sen[i]); }

		printf("Case %d:\n", ++x);
		printf("#include<string.h>\n");
		printf("#include<stdio.h>\n");
		printf("int main()\n{\n");

		for (i = 0; i < N; i++) {

			printf("printf(\"");

			for (j = 0; j < strlen(sen[i]); j++) {

				if (sen[i][j] == '"' || sen[i][j] == '\\') { printf("\\"); }				
				printf("%c", sen[i][j]);
			}

			printf("\\n\");\n");
		}

		printf("printf(\"\\n\");\n");
		printf("return 0;\n}\n");
	}

	return 0;
}
