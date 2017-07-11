#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

int main() {

	int i, round;
	string solution, guesses;
	list<char> sol, guess;
	list<char>::iterator loop;

	while (scanf("%d", &round) != EOF && round != -1) {

		getchar();

		cin >> solution >> guesses;
				
		int strokes = 0;
		bool isChickened = true;

		sol.clear(), guess.clear();
		for (i = 0; i < solution.size(); i++) { sol.push_back(solution[i]); }
		for (i = 0; i < guesses.size(); i++) { guess.push_back(guesses[i]); }
		sol.unique(), guess.unique();

		printf("Round %d\n", round);

		for (loop = guess.begin(); loop != guess.end(); loop++) {

			if (find(sol.begin(), sol.end(), *loop) != sol.end()) {

				sol.remove(*loop);
				if (sol.empty() == true) {

					printf("You win.\n");
					isChickened = false;
					break;
				}
			}
			else {

				strokes++;
				if (strokes == 7) {

					printf("You lose.\n");
					isChickened = false;
					break;
				}
			}
		}

		if (isChickened == true) { printf("You chickened out.\n"); }
	}

	return 0;
}