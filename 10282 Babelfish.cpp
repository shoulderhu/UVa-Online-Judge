#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <map>

using namespace std;

int main() {

	char input[22];
	map<string, string> dictionary;	
	string englishWord, foreignWord;

	while (gets(input) && input[0]!='\0') {
				
		bool isStop = false;
		englishWord = "", foreignWord = "";

		for (int i = 0; i < strlen(input); i++) {

			if (input[i] == ' ') { isStop = true; }
			else if (isStop == false) { englishWord += input[i]; }
			else if (isStop == true) { foreignWord += input[i]; }
		}
		
		dictionary[foreignWord] = englishWord;
	}

	while (cin >> foreignWord) {
				
		if (dictionary[foreignWord] != "") { cout << dictionary[foreignWord] << endl; }
		else { printf("eh\n"); }
	}

	return 0;
}