#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

	int N, K, M;
	char character;
	double value;
	string line;
	map<char, double> table;

	scanf("%d", &N), getchar();

	for (int i = 1; i <= N; i++) {

		scanf("%d", &K), getchar();

		table.clear();

		for (int j = 1; j <= K; j++) {

			scanf("%c %lf", &character, &value), getchar();
			table[character] = value / 100;
		}

		scanf("%d", &M), getchar();

		double pay = 0;

		for (int j = 1; j <= M; j++) {

			getline(cin, line);
			for (int k = 0; k < line.size(); k++) { pay += table[line[k]]; }
		}

		printf("%.2lf$\n", pay);
	}

	return 0;
}