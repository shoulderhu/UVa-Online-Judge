#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int cases, M, D;
	int month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	cin >> cases;

	for (int i = 0; i < cases; ++i) {

		cin >> M >> D;

		int day = D;

		for (int i = 1; i < M; ++i) { day += month[i]; }
		day = (day - 1) % 7;

		switch (day) {

		case 0: cout << "Saturday" << endl; break;
		case 1: cout << "Sunday" << endl; break;
		case 2: cout << "Monday" << endl; break;
		case 3: cout << "Tuesday" << endl; break;
		case 4: cout << "Wednesday" << endl; break;
		case 5: cout << "Thursday" << endl; break;
		case 6: cout << "Friday" << endl; break;
		}
	}

	return 0;
}