#include <stdio.h>

int main() {

	int i, j, k, l, n, cases=0;
	char string[1000000];

	while (scanf("%s", &string) != EOF) {

		getchar();

		scanf("%d", &n);
		getchar();

		printf("Case %d:\n", ++cases);

		for (k = 1; k <= n; k++) {

			scanf("%d %d", &i, &j);
			getchar();

			if (i > j) {

				int temp = i;
				i = j;
				j = temp;
			}			

			int same = string[i];
			bool flag = false;

			for (l = i+1; l <= j; l++) {

				if (same != string[l]) { 
					
					printf("No\n");
					flag = true;
					break; 
				}
			}

			if (flag == false) { printf("Yes\n"); }			
		}
	}
	
	return 0;
}