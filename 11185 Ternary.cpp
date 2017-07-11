#include <stdio.h>
#include <deque>

using namespace std;

int main() {

	int N;
	deque<int> tenary;
	deque<int>::iterator loop;

	while (scanf("%d", &N) != EOF && N >= 0) {
		
		if (N == 0) { 
			
			printf("0\n"); 
			continue;
		}

		tenary.clear();

		while (N != 0) {

			tenary.push_front(N % 3);
			N /= 3;
		}
		
		for (loop = tenary.begin(); loop != tenary.end(); loop++) { printf("%d", *loop); }
		printf("\n");
	}

	return 0;
}