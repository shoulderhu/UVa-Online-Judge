#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main() {

	int i, j, VeryLongSum[102];
	string VeryLongInteger;

	memset(VeryLongSum, 0, sizeof(VeryLongSum));

	while (cin >> VeryLongInteger && VeryLongInteger != "0") {

		int position = 102;

		for (i = VeryLongInteger.size() - 1; i >= 0; i--) {

			VeryLongSum[--position] += VeryLongInteger[i]-'0';
		}
	}

	for (i = 101; i >= 0; i--) {

		if (VeryLongSum[i] > 9) {

			VeryLongSum[i - 1] += VeryLongSum[i] / 10;
			VeryLongSum[i] %= 10;
		}		
	}

	while (VeryLongSum[++i] == 0) {}

	for (j = i; j < 102; j++) { printf("%d", VeryLongSum[j]); }
	printf("\n");

	return 0;
}