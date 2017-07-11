#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <stack>

using namespace std;

int main() {

	string line;

	while (cin >> line && line[0] != '-') {

		if (line[0] == '0') {

			int sum = 0;
			line = line.substr(2, (line.size() - 2));

			for (int i = 0; i < line.size(); i++) {

				if (isalpha(line[i]) != 0) { sum += (line[i] - 55)*pow(16, (line.size() - 1 - i)); }
				else { sum += (line[i] - '0')*pow(16, (line.size() - 1 - i)); }
			}

			printf("%d\n", sum);			
		}
		else {

			int decimal = atoi(line.c_str());
			stack<int> temp;
			
			while (decimal != 0 ) {

				temp.push(decimal % 16);					
				decimal /= 16;				
			}

			printf("0x");

			while (temp.empty() == false) {
								
				if (temp.top() < 10) { printf("%d", temp.top()); }
				else { printf("%c", temp.top() + 55); }
				temp.pop();
			}

			printf("\n");
		}
	}

	return 0;
}