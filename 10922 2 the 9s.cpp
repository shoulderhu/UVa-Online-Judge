#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int stringSum(string numberCp) {

	int sum = 0;

	for (int i = 0; i < numberCp.size(); i++) { sum += numberCp[i] - '0'; }

	return sum;
}

int digitSum(int sumCp) {

	int sum = 0;

	while (sumCp > 0) {

		sum += sumCp % 10;
		sumCp /= 10;
	}

	return sum;
}

int main() {

	string number;

	while (cin >> number && number != "0") {

		int degree = 0, sum = 0;
		
		if (number != "9") { sum = stringSum(number); }
		else {

			printf("9 is a multiple of 9 and has 9-degree 1.\n");
			continue;
		}

		while (sum != 9 && sum % 9 == 0) {

			degree++;
			sum = digitSum(sum);								
		}

		if (sum == 9) { degree++; }

		if (degree == 0) { printf("%s is not a multiple of 9.\n", number.c_str()); }
		else { printf("%s is a multiple of 9 and has 9-degree %d.\n", number.c_str(), degree); }		
	}

	return 0;
}