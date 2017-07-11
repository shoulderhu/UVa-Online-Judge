#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
		
	string skewBinary;

	while (cin >> skewBinary && skewBinary != "0") {

		int decimal = 0;

		for (int i = 0; i < skewBinary.size(); i++) {

			if (skewBinary[i] != '0') {
								
				decimal += (skewBinary[i] - '0') * (pow(2, skewBinary.size() - i) - 1);
			}			
		}

		printf("%d\n", decimal);
	}

	return 0;
}