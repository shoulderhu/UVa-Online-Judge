#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	string color = "BCG";	
	struct bin { int B, C, G; }Bin[3];

	while (scanf("%d %d %d %d %d %d %d %d %d", &Bin[0].B, &Bin[0].G, &Bin[0].C, &Bin[1].B, &Bin[1].G, &Bin[1].C, &Bin[2].B, &Bin[2].G, &Bin[2].C) != EOF) {
		
		int min = 2147483647;
		string result;

		do {
			int sum = 0;

			for (int i = 0; i < 3; i++) {

				switch (color[i]) {
				case 'B': sum += Bin[i].C, sum += Bin[i].G; break;
				case 'G': sum += Bin[i].B, sum += Bin[i].C; break;
				case 'C': sum += Bin[i].B, sum += Bin[i].G; break;
				}				
			}

			if (min > sum) { min = sum, result = color; }
			
		} while (next_permutation(color.begin(), color.end()));

		printf("%s %d\n", result.c_str(), min);
	}

	return 0;
}