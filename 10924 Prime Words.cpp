#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <map>

using namespace std;

int main() {

	int i, j;
	string word;
	map<char, int> letter;

	for (i = 'a', j = 1; i <= 'z'; i++, j++) { letter[i] = j; }
	for (i = 'A', j = 27; i <= 'Z'; i++, j++) { letter[i] = j; }

	while (cin >> word) {

		int sum = 0;
		bool isPrime = true;

		for (i = 0; i < word.size(); i++) { sum += letter[word[i]]; }

		for (i = 2; i <= sqrt(sum); i++) {

			if (sum%i == 0) {

				printf("It is not a prime word.\n");
				isPrime = false;
				break;
			}
		}

		if (isPrime == true) { printf("It is a prime word.\n"); }
	}

	return 0;
}