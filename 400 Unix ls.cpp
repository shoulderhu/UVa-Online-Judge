#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	string fileName;
	vector<string> Vector;

	while (cin >> N) {

		int length = 0;
		Vector.clear();

		for (int i = 1; i <= N; i++) {

			cin >> fileName;
			length = max(length, (int)fileName.size());
			Vector.push_back(fileName);
		}

		sort(Vector.begin(), Vector.end());

		cout << "------------------------------------------------------------\n";

		int column = (60 - length) / (length + 2) + 1, row = ceil((double)N / column);

		for (int i = 0; i < row; i++) {

			for (int j = i, p = 1; j < Vector.size(); j += row, p++) {

				cout << Vector[j];

				for (int k = (p != column ? length - Vector[j].size() + 2 : length - Vector[j].size()); k > 0; k--) { cout << " "; }
			}			
					
			cout << endl;
		}
	}

	return 0;
}