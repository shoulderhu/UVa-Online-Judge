#include <stdio.h>

int main() {

	int i, j, m, n, M[20000], N[20000];

	while (scanf("%d %d", &n, &m) != EOF) {

		if (n == 0 && m == 0) { break; }

		getchar();

		for (i = 0; i < n; i++){
			
			scanf("%d", &N[i]);
			getchar();
		}

		for (i = 0; i < m; i++) {

			scanf("%d", &M[i]);
			getchar();
		}
		
		for (i = 0; i < n - 1; i++) {

			for (j = 0; j < n - 1 - i; j++) {

				if (N[j] > N[j + 1]) {

					int temp = N[j];
					N[j] = N[j + 1];
					N[j + 1] = temp;
				}
			}
		}

		for (i = 0; i < m - 1; i++) {

			for (j = 0; j < m - 1 - i; j++) {

				if (M[j] > M[j + 1]) {

					int temp = M[j];
					M[j] = M[j + 1];
					M[j + 1] = temp;
				}
			}
		}
		
		int k = 0, coin = 0;
		bool flag;

		for (i = 0; i < n; i++) {

			flag = false;

			for (j = k; j < m; j++) {

				if (M[j] >= N[i]) { 
					
					coin += M[j];
					k = j + 1;
					flag = true;
					break;
				}
			}

			if(flag==false){ 
				
				printf("Loowater is doomed!\n"); 
				break;
			}
		}

		if (flag == true) { printf("%d\n", coin); }
	}


	return 0;
}