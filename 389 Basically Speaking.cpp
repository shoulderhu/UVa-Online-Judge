#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string>
#include <stack>

using namespace std;

int Base10(string valueCp, int fromBaseCp) {

	int sum = 0;

	for (int i = 0; i < valueCp.size(); i++) {

		if (isalpha(valueCp[i]) == 0) { sum += (valueCp[i] - '0')*pow(fromBaseCp, valueCp.size() - 1 - i); }
		else{ sum += (valueCp[i] - 55)*pow(fromBaseCp, valueCp.size() - 1 - i); }
	}

	return sum;
}

stack<int> Base(int tempCp, int toBaseCp) {
		
	stack<int> result;

	if (tempCp == 0) { result.push(0); }

	while (tempCp != 0) {

		int temp = tempCp%toBaseCp;
		if (temp > 9) { temp += 55; }

		result.push(temp);
		tempCp /= toBaseCp;
	}

	return result;
}

int main() {

	int fromBase, toBase, temp;
	string value;

	while (cin >> value >> fromBase >> toBase) {

		if (fromBase != 10) { temp = Base10(value, fromBase); }
		else { temp = atoi(value.c_str()); }
		
		if (toBase != 10) { 
			
			stack<int> result = Base(temp, toBase);
			
			if (result.size() < 8) {

				for (int i = 0; i < 7 - result.size(); i++) { printf(" "); }
				while (result.empty() == false) {

					if (result.top() > 9) { printf("%c", (char)result.top()); }
					else { printf("%d", result.top()); }
					result.pop();
				}
				printf("\n");
			}
			else { printf("  ERROR\n"); }			
		}
		else { 
			
			if (temp <= 9999999) { printf("%7d\n", temp); }
			else { printf("  ERROR\n"); }
		}		
	}

	return 0;
}
