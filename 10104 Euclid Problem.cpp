#include <stdio.h>
#include <algorithm>

using namespace std;

void GCD(int ACp, int BCp) {

	int ax = 1, ay = 0, bx = 0, by = 1;

	while (BCp != 0) {

		ax -= bx*(ACp / BCp), ay -= by*(ACp / BCp);
		ACp %= BCp;

		swap(ACp, BCp);
		swap(ax, bx);
		swap(ay, by);
	}

	printf("%d %d %d\n", ax, ay, ACp);
}

int main() {

	int A, B;

	while (scanf("%d %d", &A, &B) != EOF) { GCD(A, B); }

	return 0;
}