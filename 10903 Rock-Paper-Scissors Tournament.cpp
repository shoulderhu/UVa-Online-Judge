#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, p[2];
	bool isBL = false;
	struct table { int won = 0, lost = 0; };
	string m[2];

	while (cin >> n && n != 0) {

		if (isBL == false) { isBL = true; }
		else { cout << endl; }

		cin >> k;

		int total = k * n * (n - 1) / 2;
		vector<struct table> Vector(n + 1);
		
		for (int i = 1; i <= total; ++i) {
			
			cin >> p[0] >> m[0] >> p[1] >> m[1];

			if (m[0] == "paper") {

				if (m[1] == "rock") {

					++Vector[p[0]].won, ++Vector[p[1]].lost;
				}
				else if (m[1] == "scissors") {

					++Vector[p[0]].lost, ++Vector[p[1]].won;
				}
			}
			else if (m[0] == "scissors") {

				if (m[1] == "paper") {

					++Vector[p[0]].won, ++Vector[p[1]].lost;
				}
				else if (m[1] == "rock") {

					++Vector[p[0]].lost, ++Vector[p[1]].won;
				}
			}
			else {

				if (m[1] == "scissors") {

					++Vector[p[0]].won, ++Vector[p[1]].lost;
				}
				else if (m[1] == "paper") {

					++Vector[p[0]].lost, ++Vector[p[1]].won;
				}
			}
		}

		for (int i= 1; i <= n; ++i) {

			if (Vector[i].lost + Vector[i].won == 0) { cout << "-" << endl; }
			else {

				cout << fixed << setprecision(3)
					 << (double)Vector[i].won / (Vector[i].won + Vector[i].lost)
					 << endl;
			}			
		}
	}

	return 0;
}
