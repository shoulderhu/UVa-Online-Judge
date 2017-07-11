#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	double H, U, D, F;
	
	while (cin >> H >> U >> D >> F && H != 0) {

		double height = 0;
		F = F / 100 * U;
				
		for (int i = 1; ; ++i, U -= F) {
						
			if (U > 0) { height += U; }
			if (height > H) { cout << "success on day " << i << endl; break; }
			height -= D;
			if (height < 0) { cout << "failure on day " << i << endl; break; }
		}
	}

	return 0;
}