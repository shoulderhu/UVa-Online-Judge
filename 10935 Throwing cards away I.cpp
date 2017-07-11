#include <stdio.h>
#include <queue>

using namespace std;

int main() {

	int i, n;	

	while (scanf("%d", &n) != EOF) {

		getchar();

		if (n == 0) { break; }

		queue<int> cards;
		for (i = 1; i <= n; i++) { cards.push(i); }

		printf("Discarded cards:");

		while (cards.size() != 1) {

			if(cards.size()==2){ printf(" %d", cards.front()); }
			else{ printf(" %d,", cards.front()); }

			cards.pop();
			cards.push(cards.front());
			cards.pop();
		}

		printf("\nRemaining card: %d\n", cards.front());
	}
	
	return 0;
}