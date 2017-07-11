#include <stdio.h>
#include <map>

using namespace std;

map<int, int> occurance;

void digitOccurance(int iCp) {

	while (iCp > 0) {

		occurance[iCp % 10]++;
		iCp /= 10;
	}
}

int main() {

	int j, N, set;
	map<int, int>::iterator loop;
	
	scanf("%d", &set), getchar();

	for (int i = 1; i <= set; i++) {

		scanf("%d", &N), getchar();
		
		for (j = 0; j < 10; j++) { occurance[j] = 0; }

		for (j = 1; j <= N; j++) { digitOccurance(j); }

		for (loop = occurance.begin(); loop != occurance.end(); loop++) {

			printf("%d", loop->second);
			if (loop != --occurance.end()) { printf(" "); }
		}

		printf("\n");
	}
	
	return 0;
}