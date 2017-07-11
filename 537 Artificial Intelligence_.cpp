#include <stdio.h>
#include <iostream> 
#include <ctype.h>
#include <string>
#include <map>

using namespace std;

string line;
map<char, double> element;

void initialization(int* l, size_t* p) {

	while (line[*p + *l] != 'A' && line[*p + *l] != 'V' && line[*p + *l] != 'W') { (*l)++; }
	element[line[*p - 1]] = atof(line.substr(*p + 1, *l - 1).c_str());
	switch (line[*p + *l - 1]) {

	case 'm': element[line[*p - 1]] /= 1000; break;
	case 'k': element[line[*p - 1]] *= 1000; break;
	case 'M': element[line[*p - 1]] *= 1000000; break;
	}
}

int main() {

	int kace;
	
	scanf("%d", &kace), getchar();

	for (int i = 1; i <= kace; i++) {

		getline(cin, line);
		
		int length = 1;		
		size_t pos = line.find('=');
		element.clear();

		initialization(&length, &pos);
				
		length = 1, pos = line.rfind('=');
		initialization(&length, &pos);
						
		printf("Problem #%d\n", i);

		if (element.find('U') == element.end()) {

			printf("U=%.2lfV\n", element['P'] / element['I']);
		}
		else if (element.find('I') == element.end()) {

			printf("I=%.2lfA\n", element['P'] / element['U']);
		}
		else if (element.find('P') == element.end()) {

			printf("P=%.2lfW\n", element['U'] * element['I']);
		}
				
		printf("\n");
	}

	return 0;
}