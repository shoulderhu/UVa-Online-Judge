#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, B, H, W, p, a;
	vector<int> price, bed, temp;
	
	while (scanf("%d %d %d %d", &N, &B, &H, &W) != EOF) {

		int myMin = B + 1;
		price.clear(), bed.clear();

		for (int i = 1; i <= H; i++) {

			scanf("%d", &p), getchar();
			price.push_back(p);

			for (int j = 1; j <= W; j++) {

				scanf("%d", &a);
				temp.push_back(a);
			}

			sort(temp.begin(), temp.end());

			bed.push_back(temp[temp.size() - 1]), temp.clear();
		}

		for (int i = 0; i < bed.size(); i++) {

			if (bed[i] >= N && price[i] * N <= B) { myMin = min(myMin, price[i] * N); }
		}

		if (myMin == B + 1) { printf("stay home\n"); }
		else { printf("%d\n", myMin); }
	}
	
	return 0;
}