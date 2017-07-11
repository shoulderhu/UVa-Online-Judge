#include <iostream>
#include <set>

using namespace std;

int main() {

	int i, N, S, p = 0;
	set<int> Set;

	scanf("%d", &N), getchar();

	for (i = 1; i <= N; i++) {

		scanf("%d", &S), getchar();

		int SCp = S;
		bool isHappy = true;
		Set.clear(), Set.insert(SCp);

		while (SCp != 1) {

			int temp = 0;

			while (SCp > 0) { temp += (SCp % 10)*(SCp % 10), SCp /= 10; }

			SCp = temp;

			if (Set.find(SCp) != Set.end()) {

				isHappy = false;
				break;
			}
			else { Set.insert(SCp); }			
		}

		if (isHappy == true) { printf("Case #%d: %d is a Happy number.\n", ++p, S); }
		else { printf("Case #%d: %d is an Unhappy number.\n", ++p, S); }
	}	

	return 0;
}