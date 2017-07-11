#include <iostream>
#include <string>

using namespace std;

int main() {

	int i, j, kace;
	string word, sample = "one";

	scanf("%d", &kace), getchar();

	for (i = 1; i <= kace; i++) {

		cin >> word;

		int differ = 0;

		if (word.size() == 5) { printf("3\n"); }
		else {

			for (j = 0; j < word.size(); j++) {

				if (word[j] != sample[j]) { differ++; }
			}

			if (differ <= 1) { printf("1\n"); }
			else { printf("2\n"); }
		}
	}

	return 0;
}
