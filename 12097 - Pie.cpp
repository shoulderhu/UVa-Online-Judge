#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define PI acos(-1.0)
#define ESP 1e-4

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int Case, N, F, f;
	double L, R, M, V[10000];

	cin >> Case;

	for (int i = 0; i < Case; ++i) {

		cin >> N >> F;
		++F, L = 0, R = 0;

		for (int j = 0; j < N; ++j) {

			cin >> V[j];
			V[j] = V[j]*V[j]*PI;
			R += V[j];
		}

		R /= F;

		while (fabs(R - L) > ESP) {

			M = (L + R) / 2.0, f = 0;
			
			for (int j = 0; j < N; ++j) {

				f += (int)(V[j] / M);
			}

			f >= F ? L = M : R = M;			
		}

		cout << fixed << setprecision(4) << M << endl;
	}	

	return 0;
}