#include <iostream>
#include <algorithm>

using namespace std;

int tupel[5];

bool isExpression(int t, int value) {

	if (t == 5) { return value == 23; }
	else {

		return isExpression(t + 1, value + tupel[t]) ||
			   isExpression(t + 1, value - tupel[t]) ||
			   isExpression(t + 1, value * tupel[t]);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	while (cin >> tupel[0] >> tupel[1] >> tupel[2] >> tupel[3] >> tupel[4]) {

		if (tupel[0] == 0 && tupel[1] == 0 && tupel[2] == 0 && 
			tupel[3] == 0 && tupel[4] == 0) { break; }

		bool isExist = false;
		sort(tupel, tupel + 5);

		do {
			if (isExpression(1, tupel[0]) == true) {

				isExist = true; 
				break;
			}

		} while (next_permutation(tupel, tupel + 5) == true);

		isExist == true ? cout << "Possible\n" : cout << "Impossible\n";
	}

	return 0;
}