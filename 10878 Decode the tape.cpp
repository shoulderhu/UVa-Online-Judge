#include <stdio.h>
#include <iostream> 
#include <string>

using namespace std;

int main() {

	string tape;
	int table[] = { 0, 128, 64, 32, 16, 8, 0, 4, 2, 1 };
	bool isStop = false;

	while (getline(cin, tape)) {

		if (tape == "___________") { continue; }

		int ASCII = 0;

		for (int i = 1; i <= 9; i++) {

			if (i == 6) { continue; }
			else if (tape[i] == 'o') { ASCII += table[i]; }			
		}

		printf("%c", ASCII);
	}
	
	return 0;
}
