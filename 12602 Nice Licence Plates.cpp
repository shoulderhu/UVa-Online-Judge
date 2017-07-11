#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, DDDD;
	string plate, LLL;
	stringstream ss;
	
	cin >> N;

	for (int i = 1; i <= N; ++i) {

		cin >> plate;

		long long first = 0;
		plate[3] = ' ';
		ss.clear(), ss << plate, ss >> LLL >> DDDD;
		
		for (int j = 0; j < 3; ++j) { first += (LLL[j] - 65)*pow(26, 2 - j); }

		if (abs(DDDD - first) <= 100) { cout << "nice\n"; }
		else { cout << "not nice\n"; }
	}

	return 0;
}