#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;
	struct xy { int x, y; }XY;
	vector<struct xy> solution;

	while (cin >> k) {
				
		solution.clear();

		for (double i = 1; i <= 2 * k; ++i) {

			double temp = k*i / (i - k);

			if (temp > 0 && temp == (int)temp) {

				XY.x = temp, XY.y = i;
				solution.push_back(XY);
			}
		}
		
		cout << solution.size() << endl;

		for (int i = 0; i < solution.size(); ++i) {

			cout << "1/" << k << " = 1/" << solution[i].x << " + 1/" << solution[i].y << endl;
		}		
	}

	return 0;
}
