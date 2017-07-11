#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n, m, c, operation, sequence = 0;
	struct device{
		
		int consumption;
		bool isSwitch = false;
	}Device;
	vector<struct device> Vector;

	while (scanf("%d %d %d", &n, &m, &c) != EOF && !(n == 0 && m == 0 && c == 0)) {

		Vector.clear();

		for (int i = 1; i <= n; i++) {

			scanf("%d", &Device.consumption);
			Vector.push_back(Device);
		}

		int sum = 0, myMax = 0;
		bool isBlow = false;

		for (int i = 1; i <= m; i++) {

			scanf("%d", &operation);

			if (isBlow == false) {

				if (Vector[operation - 1].isSwitch == false) {

					sum += Vector[operation - 1].consumption;
					Vector[operation - 1].isSwitch = true;

					if (sum > c) { isBlow = true; }
					else { myMax = max(myMax, sum); }
				}
				else {

					sum -= Vector[operation - 1].consumption;
					Vector[operation - 1].isSwitch = false;
				}
			}			
		}

		printf("Sequence %d\n", ++sequence);
		if (isBlow == true) { printf("Fuse was blown.\n"); }
		else { 
			
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n", myMax);
		}
		printf("\n");
	}

	return 0;
}