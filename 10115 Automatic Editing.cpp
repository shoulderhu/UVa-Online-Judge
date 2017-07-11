#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	
	int rule;
	struct table { string find, replace; }line;
	string input;
	vector<struct table> replacement;
	vector<struct table>::iterator iter;
	
	while (scanf("%d", &rule) != EOF && rule != 0) {

		getchar();

		replacement.clear();

		for (int i = 1; i <= rule; i++) {

			getline(cin, line.find);
			getline(cin, line.replace);			
			replacement.push_back(line);
		}

		getline(cin, input);

		for (iter = replacement.begin(); iter != replacement.end(); iter++) {
			
			size_t found = input.find((*iter).find);

			while (found != string::npos) {

				input.replace(found, (*iter).find.size(), (*iter).replace);
				found = input.find((*iter).find);
			}
		}

		printf("%s\n", input.c_str());
	}

	return 0;
}