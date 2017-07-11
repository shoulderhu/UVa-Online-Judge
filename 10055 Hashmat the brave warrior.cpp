#include <stdio.h>
#include <stdlib.h>

int main() {

	long long int hashmat, opponent, num;

	while (scanf("%lld %lld", &hashmat, &opponent) != EOF) {

		num = llabs(hashmat - opponent);

		printf("%lld\n", num);
	}

	return 0;
}