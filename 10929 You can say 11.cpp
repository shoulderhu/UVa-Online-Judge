#include <stdio.h> 
#include <iostream>
#include <string>

using namespace std;

int main() {

	int i;
	string number;

	while (cin >> number && number != "0") {

		int oddSum = 0, evenSum = 0;

		for (i = 0; i < number.size(); i++) {

			if (i % 2 == 0) { evenSum += number[i] - '0'; }
			else { oddSum += number[i] - '0'; }
		}
		
		if ((oddSum - evenSum) % 11 == 0) {
			
			printf("%s is a multiple of 11.\n", number.c_str());			
		}
		else { printf("%s is not a multiple of 11.\n", number.c_str()); }
	}

	return 0;
}
