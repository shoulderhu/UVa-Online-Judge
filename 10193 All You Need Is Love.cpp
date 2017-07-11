#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

int toDecimal(string SCp) {

	int sum = 0;

	for (int i = 0; i < SCp.size(); i++) {

		if (SCp[i] == '1') { sum += (int)pow(2, SCp.size() - i - 1); }
	}

	return sum;
}

int GCD(int D1Cp, int D2Cp) {

	while (D2Cp > 0) {

		D1Cp %= D2Cp;
		swap(D1Cp, D2Cp);
	}

	return D1Cp;
}

int main() {

	int N;
	string S1, S2;

	scanf("%d", &N), getchar();

	for (int i = 1; i <= N; i++) {
		
		cin >> S1 >> S2;
		
		int D1 = toDecimal(S1), D2 = toDecimal(S2), L = GCD(D1, D2);
				
		printf("Pair #%d: ", i);		
		printf(L != 1 ? "All you need is love!\n": "Love is not all you need!\n");		
	}

	return 0;
}
