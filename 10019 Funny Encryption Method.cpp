#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main() {

	int i, j, N, M, power2[14];
	map<int, int> table;
	
	for (i = 0; i < 14; i++) { power2[i] = pow(2, i); }

	for (i = 0; i < 16; i++) {

		switch (i) {

		case 0: 
			table[i] = 0;
		break;

		case 1: case 2: case 4: case 8:
			table[i] = 1;
		break;

		case 3: case 5: case 6: case 9: case 10: case 12:
			table[i] = 2;
		break;

		case 7: case 11: case 13: case 14:
			table[i] = 3;
		break;

		case 15:
			table[i] = 4;
		break;
		}
	}

	scanf("%d", &N), getchar();

	for (i = 1; i <= N; i++) {

		scanf("%d", &M), getchar();

		int b1 = 0, b2 = 0, MCp = M;

		for (j = 13; j >= 0; j--) {

			while (MCp >= power2[j]) { MCp -= power2[j], b1++; }
		}

		MCp = M;

		while (MCp > 0) { b2 += table[MCp % 10], MCp /= 10; }

		printf("%d %d\n", b1, b2);
	}

	return 0;
}