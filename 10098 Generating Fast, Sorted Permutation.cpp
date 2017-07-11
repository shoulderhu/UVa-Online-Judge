#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	int n;
	string str;

	scanf("%d", &n), getchar();

	for (int i = 1; i <= n; i++) {

		cin >> str;

		sort(str.begin(), str.end());

		do {
			printf("%s\n", str.c_str());

		} while (next_permutation(str.begin(), str.end()) == true);

		printf("\n");
	}

	return 0;
}