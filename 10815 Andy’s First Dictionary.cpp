#include <stdio.h>
#include <iostream>
#include <string>
#include <ctype.h>
#include <set>

using namespace std;

int main() {

	char ch, word[201];
	int start = -1;
	set<string> dictionary;
	set<string> ::iterator loop;
	
	while (ch=getchar()) {

		if (ch == EOF) { break; }
		else if (isalpha(ch) != 0) { word[++start] = tolower(ch); }
		else{
		
			word[++start] = '\0';
			if (start > 0) { dictionary.insert(word); }
			start = -1;
		}		
	}

	for (loop = dictionary.begin(); loop != dictionary.end(); loop++) {

		cout << *loop << endl;
	}

	return 0;
}