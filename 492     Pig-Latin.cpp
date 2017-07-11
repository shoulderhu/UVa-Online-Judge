#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

void pigLatin(string subLineCp) {

	if (tolower(subLineCp[0]) == 'a' || tolower(subLineCp[0]) == 'e' || tolower(subLineCp[0]) == 'i' || tolower(subLineCp[0]) == 'o' || tolower(subLineCp[0]) == 'u') {

		subLineCp.append("ay");
		printf("%s", subLineCp.c_str());
	}
	else {
				
		subLineCp.append(subLineCp.substr(0, 1));
		subLineCp.erase(0, 1);
		subLineCp.append("ay");
		printf("%s", subLineCp.c_str());
	}
}

int main() {

	int i;
	string line;

	while (getline(cin, line)) {

		for (i = 0; i < line.size(); i++) {

			if (isalpha(line[i]) != 0) {

				string subLine = "";
				subLine += line[i];

				while (isalpha(line[++i]) != 0) { subLine += line[i]; }
				pigLatin(subLine);				
			}

			printf("%c", line[i]);
		}

		printf("\n");
	}

	return 0;
}