#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
		
	int pointer;
	string X, Y;

	while (cin >> X) {

		cin >> Y;

		int result[501] = { 0 }, end = 501;

		for (int i = Y.size() - 1; i >= 0; i--) {

			pointer = --end;

			for (int j = X.size() - 1; j >= 0; j--) {

				result[pointer] += (Y[i] - '0')*(X[j] - '0');

				if (result[pointer] > 9) {

					result[pointer - 1] += result[pointer] / 10;
					result[pointer] %= 10;										
				}	

				pointer--;
			}
		}
		
		if (pointer == -1) { pointer++; }
		else {

			while (result[pointer] == 0) { 
				
				pointer++;

				if (pointer > 500) { 
					
					pointer--;
					break;
				}
			} 
		}

		for (int i = pointer; i < 501; i++) { printf("%d", result[i]); }
		printf("\n");
	}

	return 0;
}