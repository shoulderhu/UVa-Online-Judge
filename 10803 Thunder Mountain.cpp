#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#define Error 1e-9

using namespace std;

struct xy { double x = 0, y = 0; } XY;

inline double far(struct xy a, struct xy b) { 
	
	return sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0));
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, n, kace = 0;
	double wood[101][101];

	cin >> N;

	for (int i = 1; i <= N; ++i) {

		cin >> n;

		double maxDistance = 0;
		vector<struct xy> Vector;
	    Vector.push_back(XY);

		for (int j = 1; j <= n; ++j) {

			cin >> XY.x >> XY.y;
			Vector.push_back(XY);
		}

		for (int j = 1; j <= n; ++j) {

			for (int k = 1; k <= n; ++k) {

				if (j == k) { wood[j][k] = 0; }
				else {
				
					double d = far(Vector[j], Vector[k]);

					if (d <= 10) { wood[j][k] = d; }
					else { wood[j][k] = 143228; }
				}
			}
		}

		for (int j = 1; j <= n; ++j) {

			for (int k = 1; k <= n; ++k) {

				for (int l = 1; l <= n; ++l) {

					wood[k][l] = min(wood[k][l], wood[k][j] + wood[j][l]);
				}
			}
		}

		for (int j = 1; j <= n; ++j) {

			for (int k = 1; k <= n; ++k) {

				if (wood[j][k] != 0) {

					maxDistance = max(maxDistance, wood[j][k]);
				}
			}
		}

		cout << "Case #" << ++kace << ":" << endl;

		if (fabs(maxDistance - 143228) <= Error) { cout << "Send Kurdy" << endl; }
		else{ cout << fixed << setprecision(4) << maxDistance << endl; }	

		cout << endl;
	}
	
	return 0;
}
