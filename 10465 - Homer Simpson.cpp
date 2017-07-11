#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int mn[2], t, K[10000], KK[10000];
	
	while (cin >> mn[0] >> mn[1] >> t) {

		memset(K, 0, sizeof(K));
		memset(KK, 0, sizeof(KK));

		for (int i = 0; i < 2; ++i) {
			
			for (int j = mn[i]; j <= t; ++j) {

				if (K[j] < K[j - mn[i]] + mn[i]) {

					K[j] = K[j - mn[i]] + mn[i];
					KK[j] = KK[j - mn[i]] + 1;					
				}
				else if (K[j] == K[j - mn[i]] + mn[i]) {

					KK[j] = max(KK[j - mn[i]] + 1, KK[j]);
				}
			}					
		}

		if (K[t] == t) { cout << KK[t] << endl; }
		else { cout << KK[t] << " " << t - K[t] << endl; }		
	}

	return 0;
}