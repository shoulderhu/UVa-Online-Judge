#include <iostream>
#include <map>

using namespace std;

int main() {

	int i, integer;		
	map<int, map<char, int>> romanDigit;
		
	for (i = 1; i <= 100; i++) {

		int iCp = i;
				
		if (iCp == 100) { romanDigit[i]['c']++, iCp -= 100; }
		
		if (10 <= iCp) {
			
			if (0 <= (iCp - 90) && (iCp - 90) < 10) { romanDigit[i]['x']++, romanDigit[i]['c']++, iCp -= 90; }
			else if (0 <= (iCp - 40) && (iCp - 40) < 10) { romanDigit[i]['x']++, romanDigit[i]['l']++, iCp -= 40; }
			else {

				while (iCp >= 50) { romanDigit[i]['l']++, iCp -= 50; }
				while (iCp >= 10) { romanDigit[i]['x']++, iCp -= 10; }
			}
		}

		if (0 < iCp) {

			if (iCp == 4) { romanDigit[i]['i']++, romanDigit[i]['v']++, iCp -= 4; }
			else if (iCp == 9) { romanDigit[i]['i']++, romanDigit[i]['x']++, iCp -= 9; }
			else {

				while (iCp >= 5) { romanDigit[i]['v']++, iCp -= 5; }
				while (iCp >= 1) { romanDigit[i]['i']++, iCp -= 1; }
			}
		}		
	}

	while (scanf("%d", &integer) && integer != 0) {
		
		int iSum = 0, vSum = 0, xSum = 0, lSum = 0, cSum = 0;

		for (i = 1;i <= integer; i++) {

			iSum += romanDigit[i]['i'];
			vSum += romanDigit[i]['v'];
			xSum += romanDigit[i]['x'];
			lSum += romanDigit[i]['l'];
			cSum += romanDigit[i]['c'];
		}
		
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", integer, iSum, vSum, xSum, lSum, cSum);
	}

	return 0;
}
