#include <iostream>
#include <algorithm>

using namespace std;

int a, b;

bool isSquareNumber(int squareCp) {

	if (a <= squareCp && squareCp <= b) { return true; }

	return false;
}

int main() {

	int i, square[316], position = -1;

	for (i = 1; ; i++) {

		if (i*i > 100000) { break; }
		square[++position] = i*i;		
	}
		
	while (scanf("%d %d", &a, &b) != EOF && a != 0 && b != 0) {
		
		int sum = count_if(square, square + 316, isSquareNumber);

		printf("%d\n", sum);
	}

	return 0;
}