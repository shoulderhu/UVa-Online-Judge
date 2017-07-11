#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int n, x = 0;
double jump[1000][1000];
struct stone { int x, y; }S[1000];

inline double distance(struct stone &a, struct stone &b) {

	return sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0));
}

int main() {

	ios::sync_with_stdio(false);
	
	while (cin >> n && n != 0) {

		for (int i = 0; i < n; ++i) {

			cin >> S[i].x >> S[i].y;
		}

		for (int i = 0; i < n; ++i) {

			jump[i][i] = 0;

			for (int j = i + 1; j < n; ++j) {

				jump[i][j] = distance(S[i], S[j]);
				jump[j][i] = jump[i][j];				
			}			
		}

		for (int i = 0; i < n; ++i) {

			for (int j = 0; j < n; ++j) {

				for (int k = 0; k < n; ++k) {

					jump[j][k] = min(jump[j][k], max(jump[j][i], jump[i][k]));
				}
			}
		}

		cout << "Scenario #" << ++x << endl << "Frog Distance = "
			 << fixed << setprecision(3) << jump[0][1] << endl << endl;
	}

	return 0;
}
