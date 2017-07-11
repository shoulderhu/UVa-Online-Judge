#include <stdio.h>
#define boundary 1000001

int d(int iCp) {

	int sum = iCp;

	while (iCp > 0) { sum += iCp % 10, iCp /= 10; }

	return sum;
}

int main() {

	int i;
	bool selfNumbers[boundary];

	for (i = 1; i < boundary; i++) { selfNumbers[i] = true; }

	for (i = 1; i < boundary; i++) {
		
		int generated = d(i);
		if (generated < boundary) { selfNumbers[generated] = false; }
	}

	for (i = 1; i < boundary; i++) {

		if(selfNumbers[i]==true){ printf("%d\n", i); }		
	}

	return 0;
}