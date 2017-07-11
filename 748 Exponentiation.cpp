#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

int main() {
		
	int n, value[125];	
	string R;
		
	while (cin >> R >> n) {
		
		memset(value, 0, sizeof(value));
		value[124] = 1;

		int dot = (R.size() - R.find('.') - 1) * n;
		R.erase(R.find('.'), 1);
		int r = atoi(R.c_str()), carry = 0, begin = 0, end = 124;
		
		for (int i = 1; i <= n; i++) {

			for (int j = 124; j >= 0; j--) {

				value[j] = value[j] * r + carry;
				carry = 0;

				if (value[j] >= 10) {

					carry = value[j] / 10;
					value[j] %= 10;
				}
			}
		}
				
		while (value[begin] == 0) { begin++; }
		while (value[end] == 0) { end--; }

		if ((124 - begin + 1) < dot) {
			
			printf(".");
			for (int i = 1; i <= dot - (124 - begin + 1); i++) { printf("0"); }
		}

		for (int i = begin; i <= end; i++) { 
			
			if ((124 - i + 1) == dot) { printf("."); }
			printf("%d", value[i]); 		
		}
		printf("\n");
	}

	return 0;
}
