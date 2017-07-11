#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	
	int coin[] = { 1, 5, 10, 25, 50 }, money, Coin, j;
	long long int comb[30001] = { 1 };

	for (int i = 0; i < 5; ++i) {
		
		for (int j = coin[i]; j < 30001; ++j) {
						
			comb[j] += comb[j - coin[i]];
		}
	}

	while (cin >> money) {

		if (money < 5) {
			
			cout << "There is only 1 way to produce " << money << " cents change." << endl;
			continue;
		}
		
		cout << "There are " << comb[money] << " ways to produce " << money << " cents change." 
			 << endl; 
	}

	return 0;
}