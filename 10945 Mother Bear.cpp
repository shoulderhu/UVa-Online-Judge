#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

bool isPalindrome(string senCp) {
	
	int bound = senCp.size() % 2 == 0 ? senCp.size() / 2 : (senCp.size() - 1) / 2;

	for (int i = 0; i < bound; i++) {
				
		if (senCp[i] != senCp[senCp.size() - 1 - i]) { return false; }
	}

	return true;
}

int main() {
	
	string sen;

	while (getline(cin, sen) && sen != "DONE") {
		
		for (int i = 0; i < sen.size(); i++) {
						
			while (i < sen.size() && isalpha(sen[i]) == 0) { sen.erase(i, 1); }
			sen[i] = tolower(sen[i]);
		}
			
		if (isPalindrome(sen) == false) { printf("Uh oh..\n"); }
		else { printf("You won't be eaten!\n"); }			
	}

	return 0;
}