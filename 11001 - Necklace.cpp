#include <iostream>
#include <cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int disc;
	double Vt, V0, V, D, longest;

	while (cin >> Vt >> V0 && !(Vt == 0 && V0 == 0)) {

		longest = 0, disc = 0;

		for (int i = 1; ; ++i) {

			V = Vt / i;
			if (V <= V0) { break; }
			D = 0.3 * sqrt(V - V0) * i;
			
			if (fabs(D - longest) < 1e-9) {

				disc = 0;
			}
			else if (D > longest) {

				longest = D;
				disc = i;
			}
		}

		cout << disc << '\n';		
	}

	return 0;
}