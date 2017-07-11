#include <stdio.h>
#include <map>

using namespace std;

int main() {

	int N;
	map<int, int> prime;
	map<int, int>::iterator loop;

	while (scanf("%d", &N) != EOF && N != 0) {

		prime.clear();

		for (int i = 2; i <= N; i++) {

			int iCp = i;
			
			for (int j = 2; j <= iCp; j++) {

				while (iCp%j == 0) { 
					
					prime[j]++; 					
					iCp /= j;
				}
			}						
		}

		int size = 0;

		printf("%3d! =", N);

		for (loop = prime.begin(); loop != prime.end(); loop++) {

			size++;
			if (size > 15 && size % 15 == 1) { printf("\n      "); }

			printf("%3d", loop->second);
		}

		printf("\n");
	}
	
	return 0;
}