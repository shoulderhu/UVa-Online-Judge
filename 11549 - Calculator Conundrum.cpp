#include <iostream>
#include <cmath>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {

	int t, n, v;
	long long int k;	
	string K;

	cin >> t;

	for (int i = 0; i < t; ++i) {

		cin >> n >> k;

		int Pow = pow(10, n);
		long long int Max = k;
		unordered_set<long long int> Set;
				
		do{

			Set.insert(k), Max = max(Max, k), k *= k;
			
			if (k >= Pow) {

				v = 0, K = to_string(k);

				for (int j = 0; j < K.size() && j < n; ++j) {

					v = v * 10 + (K[j] - '0');
				}

				k = v;
			}			
		} while (Set.find(k) == Set.end());
		
		cout << Max << endl;
	}

	return 0;
}