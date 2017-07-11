#include <iostream>
#include <iomanip>
#include <map>
#include <vector>

using namespace std;

int main() {

	int num;
	vector<map<int, int>> Vector(367);
	vector<int> factorial(781, 0);
	Vector[1][1]++, factorial[780] = 1;
	
	for (int i = 2; i < 367; ++i) {

		int carry = 0, begin = 0;

		for (int j = 780; j >= 0; --j) {

			factorial[j] = factorial[j] * i + carry;
			carry = 0;

			if (factorial[j] > 9) {

				carry = factorial[j] / 10;
				factorial[j] %= 10;
			}
		}

		while (factorial[begin] == 0) { begin++; }
		for (int j = begin; j < 781; ++j) { Vector[i][factorial[j]]++; }
	}

	while (cin >> num && num != 0) {

		cout << num << "! --" << endl;

		for (int i = 0; i < 10; ++i) {

			cout << "   (" << i << ")" << setw(5) << Vector[num][i];
			if (i == 4 || i == 9) { cout << endl; }
			else { cout << " "; }
		}
	}	

	return 0;
}