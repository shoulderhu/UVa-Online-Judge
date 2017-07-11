#include <stdio.h>
#include <algorithm>

using namespace std;

int GCD(int num1, int num2) {

	while (num2 != 0) {

		num1 %= num2;
		swap(num1, num2);
	}

	return num1;
}

int main() {

	int j, num[1001];

	while (scanf("%d", &num[0]) != EOF && num[0] != 0) {

		int i = 0;

		while (scanf("%d", &num[++i]) != EOF && num[i] != 0) { getchar(); }
		
		sort(num, num + i);

		for (j = 1; j < i; j++) { num[j] -= num[0]; }
		
		int result = GCD(num[1], num[2]);

		for (j = 3; j < i; j++) { result = GCD(result, num[j]); }

		printf("%d\n", result);
	}

	return 0;
}