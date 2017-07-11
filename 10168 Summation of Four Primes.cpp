#include <stdio.h>
#include <vector>

using namespace std;

vector<bool> prime(10000001, true);

int searching(int NCp) {

	if (prime[NCp - 2] == true) { return 2; }
	else {

		for (int i = 3; i < 10000000; i += 2) {

			if (prime[i] == true && prime[NCp - i] == true) { return i; }
		}
	}	
}

int main() {

	int N;		
	prime[0] = false, prime[1] = false;
	
	for (int i = 2; i < 5000000; i++) {

		if (prime[i] == true) {

			for (int j = 2 * i; j <= 10000000; j += i) { prime[j] = false; }
		}
	}

	while (scanf("%d", &N) != EOF) {

		if (N < 8) { printf("Impossible.\n"); }
		else { 
			
			if (N % 2 == 0) { 
				
				int temp = searching(N - 4);

				printf("2 2 %d %d\n", temp, N - 4 - temp);
			}
			else{ 
				
				int temp = searching(N - 5);

				printf("2 3 %d %d\n", temp, N - 5 - temp);
			}
		}
	}

	return 0;
}