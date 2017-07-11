#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int main() {

	int input2;
	char sign;
	string input1;
	vector<int> result;

	while (cin >> input1 >> sign >> input2) {
		
		if (sign == '%') {
				
			long long int result = 0;

			for (int i = 0; i < input1.size(); i++) {
				
				result = (result * 10 + (input1[i] - '0')) % input2;			
			}

			printf("%lld\n", result);
		}
		else {
			
			if (input1.size() < 10) { printf("%d\n", atoi(input1.c_str()) / input2); }
			else {
												
				int pos = 0;
				long long int temp = 0;
				result.clear();

				for (int i = 0; i < input1.size(); i++) {

					temp = temp * 10 + (input1[i] - '0');
					result.push_back(temp / input2);
					temp %= input2;
				}

				while (result[pos] == 0) { pos++; }

				for (vector<int>::iterator iter = result.begin()+pos; iter != result.end(); iter++) {
					
					printf("%d", *iter);
				}
				printf("\n");
			}			
		}
	}

	return 0;
}
