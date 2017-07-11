#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	
	int i;
	string line;
	stack<char> temp;

	while (getline(cin, line)) {

		for (i = 0; i < line.size(); i++) {

			if (line[i] != ' ') { temp.push(line[i]); }
			else {

				while (temp.empty() == false) {
					
					printf("%c", temp.top());
					temp.pop();
				}

				printf(" ");
			}
		}

		while (temp.empty() == false) {
			
			printf("%c", temp.top());
			temp.pop();
		}

		printf("\n");
	}

	return 0;
}