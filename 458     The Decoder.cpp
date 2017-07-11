#include <iostream>
#include <string>

using namespace std;

int main() {

	int i;
	string input;

	while (getline(cin, input)) {

		for (i = 0; i < input.size(); i++) { printf("%c", input[i] - 7); }
		printf("\n");
	}

	return 0;
}