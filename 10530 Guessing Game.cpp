#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	int guess, low = 0, high = 11;
	string response;

	while (scanf("%d", &guess) != EOF && guess != 0) {

		getchar();

		getline(cin, response);

		if (response == "too high") { if (high > guess) { high = guess; } }
		else if (response == "too low") { if (low < guess) { low = guess; } }
		else {

			if (low < guess && guess < high) { printf("Stan may be honest\n"); }
			else { printf("Stan is dishonest\n"); }

			low = 0, high = 11;
		}
	}

	return 0;
}