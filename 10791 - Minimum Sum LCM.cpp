#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int Case = 0, e, p;
	double Sqrt;
	long long int N, summation;
		
	while (cin >> N && N != 0) {
				
		p = 0, summation = 0, Sqrt = sqrt(N);
		if (N == 1) { summation = 1; }

		for (int i = 2; i <= Sqrt; ++i) {

			e = 0;
			while (N%i == 0) { ++e, N /= i; }
			if (e != 0) { summation += pow(i, e), ++p; }
		}

		if (N > 1) { summation += N, ++p; }

		cout << "Case " << ++Case << ": ";
		if (p > 1) { cout << summation << endl; }
		else { cout << summation + 1 << endl; }
	}
	
	return 0;
}