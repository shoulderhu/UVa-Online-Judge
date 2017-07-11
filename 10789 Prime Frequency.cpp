#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	int T, prime[304] = {0, 2}, p = 1;
	string input;
	map<char, int> frequency;
	map<char, int>::iterator loop;

	for (int i = 3; i < 2000; i += 2) {

		bool isPrime = true;

		for (int j = 2; j <= sqrt(i); j++) {

			if (i%j == 0) {

				isPrime = false;
				break;
			}
		}

		if (isPrime == true) { prime[++p] = i; }
	}

	scanf("%d", &T), getchar();

	for (int i = 1; i <= T; i++) {

		cin >> input;

		frequency.clear();
		for (int j = 0; j < input.size(); j++) { frequency[input[j]]++; }

		printf("Case %d: ", i);

		bool isPrint = false;

		for (loop = frequency.begin(); loop != frequency.end(); loop++) {

			if (find(prime + 1, prime + 304, loop->second) != prime + 304) {

				printf("%c", loop->first);
				isPrint = true;
			}			
		}

		if (isPrint == false) { printf("empty"); }

		printf("\n");
	}

	return 0;
}