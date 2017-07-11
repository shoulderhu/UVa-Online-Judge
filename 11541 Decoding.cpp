#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, kace = 0;
	string line;

	cin >> T;

	for (int i = 1; i <= T; i++) {

		cin >> line;
		cout << "Case " << ++kace << ": ";

		for (int j = 0; j < line.size(); j += 2) {

			char letter = line[j];
			int time = line[j + 1] - '0';

			while (isdigit(line[j + 2]) != 0) {	
				
				time = time * 10 + (line[j + 2] - '0'), j++;
			}
			
			for (int k = 1; k <= time; k++) { cout << letter; }			
		}

		cout << endl;
	}

	return 0;
}