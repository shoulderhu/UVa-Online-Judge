#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int S, kace = 0, month[13], require;

	while (cin >> S && S >= 0) {

		for (int i = 1; i < 13; ++i) { cin >> month[i]; }
		
		cout << "Case " << ++kace << ":" << endl;

		for (int i = 1; i < 13; ++i) {

			cin >> require;
			cout << "No problem";

			if (S >= require) {

				cout << "! :D" << endl;
				S -= require;
			}
			else { cout << ". :(" << endl; }
						 
			S += month[i];
		}	
	}

	return 0;
}