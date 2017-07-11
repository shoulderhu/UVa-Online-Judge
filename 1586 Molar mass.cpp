#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <map>

using namespace std;

int main() {

	int T, length;
	string formula;
	map<char, double> table = { {'C', 12.01}, {'H', 1.008}, {'O', 16.00}, {'N', 14.01} };

	scanf("%d", &T), getchar();

	for (int i = 1; i <= T; i++) {

		cin >> formula;
				
		double mass = 0;

		for (int j = 0; j < formula.size(); j += length) {
			
			length = 1;

			while (j + length < formula.size() && isalpha(formula[j + length]) == 0) { length++; }
			
			if (length == 1) { mass += table[formula[j]]; }
			else{ mass += table[formula[j]] * atoi(formula.substr(j + 1, length - 1).c_str()); }			
		}

		printf("%.3lf\n", mass);
	}

	return 0;
}