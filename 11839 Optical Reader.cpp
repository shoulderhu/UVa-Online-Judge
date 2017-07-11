#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, gray;
	char alternative;

	while (cin >> N && N != 0) {
		
		for (int i = 0; i < N; ++i) {

			int correct = 0;
			
			for (int j = 0; j < 5; ++j) {

				cin >> gray;
				if (gray <= 127 && ++correct == 1) { alternative = j + 65; }
			}

			correct == 1 ? cout << alternative << endl : cout << "*" << endl;
		}		
	}
	
	return 0;
}