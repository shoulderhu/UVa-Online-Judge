#include <iostream>
#include <string>
#include <ctype.h>
#include <map>

using namespace std;

int main() {
		
	string line;
	map<char, int> frequency;
	map<char, int>::iterator loop;

	while (getline(cin, line)) {

		frequency.clear();

		int max = 0;

		for (int i = 0; i < line.size(); i++) {

			if (isalpha(line[i]) != 0) { 
				
				frequency[line[i]]++; 

				if (frequency[line[i]]>max) { max = frequency[line[i]]; }
			}
		}

		for (loop = frequency.begin(); loop != frequency.end(); loop++) {

			if (loop->second == max) { printf("%c", loop->first); }
		}

		printf(" %d\n", max);
	}

	return 0;
}