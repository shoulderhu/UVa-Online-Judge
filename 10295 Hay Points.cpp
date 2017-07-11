#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

	int i, m, n, dollar;
	string word;
	map<string, int> hay;

	scanf("%d %d", &m, &n), getchar();

	for (i = 1; i <= m; i++) {

		cin >> word >> dollar;
		hay[word] = dollar;
	}

	for (i = 1; i <= n; i++) {

		int sum = 0;

		while (cin >> word && word != ".") { sum += hay[word]; }
		printf("%d\n", sum);
	}

	return 0;
}