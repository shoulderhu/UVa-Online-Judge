#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, num;
	
	while (cin >> N && N != 0) {

		vector<int> Vector;

		for (int i = 1; i <= N; ++i) {

			cin >> num;
			if (num != 0) { Vector.push_back(num); }		
		}

		int length = Vector.size();

		if (length == 0) { cout << "0\n"; }
		else {
			
			for (int i = 0; i < length; ++i) {

				cout << Vector[i];

				if (i != length - 1) { cout << " "; }
				else { cout << endl; }
			}
		}
	}

	return 0;
}