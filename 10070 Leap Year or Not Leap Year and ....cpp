#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	string year;
	bool isBlank = false;

	while (cin >> year) {

		isBlank == false ? isBlank = true : printf("\n");
		
		int year4 = 0, year100 = 0, year400 = 0, year15 = 0, year55 = 0;
		bool isLeap = false, isFestival = false;

		for (int i = 0; i < year.size(); i++) { 
			
			year4 = (year4 * 10 + (year[i] - '0')) % 4;
			year100 = (year100 * 10 + (year[i] - '0')) % 100;
			year400 = (year400 * 10 + (year[i] - '0')) % 400;
			year15 = (year15 * 10 + (year[i] - '0')) % 15;
			year55 = (year55 * 10 + (year[i] - '0')) % 55;
		}

		if ((year100 != 0 && year4 == 0) || year400 == 0) {
						
			printf("This is leap year.\n"); 
			isLeap = true;					
		}

		if (year15 == 0) {
			
			printf("This is huluculu festival year.\n"); 
			isFestival = true;
		}

		if (isLeap == true && year55 == 0) {
						
			printf("This is bulukulu festival year.\n");			
		}

		if (isLeap == false && isFestival == false) {
			
			printf("This is an ordinary year.\n");
		}		
	}

	return 0;
}