#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int main() {

	int S;
	vector<int> twinPrime;
	vector<bool> Prime(18409202, true);	
	Prime[0] = false, Prime[1] = false;

	for (int i = 2; i < 18409202; i++) {

		if (Prime[i] == true) {

			for (int j = i + i; j < 18409202; j += i) { Prime[j] = false; }
			if (Prime[i - 2] == true) { twinPrime.push_back(i - 2); }
		}
	}
		
	while (scanf("%d", &S) != EOF) {
				
		printf("(%d, %d)\n", twinPrime[S - 1], twinPrime[S - 1] + 2);
	}

	return 0;
}