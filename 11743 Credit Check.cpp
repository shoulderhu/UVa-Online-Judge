#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, value;
	string line;

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		
		int doubled = 0, undoubled = 0;

		for (int j = 1; j <= 4; ++j) {

			cin >> line;
			undoubled += (line[1] - '0') + (line[3] - '0');
			
			value = (line[0] - '0') * 2;						
			while (value > 0) { doubled += value % 10, value /= 10; }

			value = (line[2] - '0') * 2;
			while (value > 0) { doubled += value % 10, value /= 10; }
		}

		(doubled + undoubled) % 10 != 0 ? cout << "Invalid" << endl : cout << "Valid" << endl;
	}

	return 0;
}