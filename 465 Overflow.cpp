#include <stdio.h>
#include <stdlib.h>
#define intMax 2147463647

int main() {

	char operators, first[1000], second[1000];
	
	while (scanf("%s %c %s", &first, &operators, &second) != EOF) {

		printf("%s %c %s\n", first, operators, second);

		double First = atof(first), Second = atof(second);

		if (First > intMax) { printf("first number too big\n"); }
		if (Second > intMax) { printf("second number too big\n"); }
		if (operators == '+' && First + Second > intMax) { printf("result too big\n"); }
		else if (operators == '*' && First * Second > intMax) { printf("result too big\n"); }
	}

	return 0;
}