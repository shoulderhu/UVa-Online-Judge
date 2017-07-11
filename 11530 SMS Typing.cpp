#include <iostream>
#include <string>

using namespace std;

int main() {

	int i, j, T;
	string line;

	scanf("%d", &T), getchar();

	for (i = 1; i <= T; i++) {

		int press = 0;

		getline(cin, line);

		for (j = 0; j < line.size(); j++) {

			switch (line[j]) {

			case 'a': case 'd': case 'g': case 'j': 
			case 'm': case 'p':	case 't': case 'w':
			case ' ':
				press++;
			break;

			case 'b': case 'e': case 'h': case 'k':
			case 'n': case 'q': case 'u': case 'x':
				press += 2;
			break;

			case 'c': case 'f': case 'i': case 'l': 
			case 'o': case 'r': case 'v': case 'y':
				press += 3;
			break;

			case 's': case 'z':
				press += 4;
			break;
			}
		}

		printf("Case #%d: %d\n", i, press);
	}

	return 0;
}