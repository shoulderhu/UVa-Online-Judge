#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace;
	string line;

	cin >> kace;

	for (int i = 1; i <= kace; ++i) {

		cin >> line;

		for (int j = line.size() / 3.0; ; ++j) {

			if (j == 0) { continue; }

			string a = line.substr(0, j), b = line.substr(j, j);
			
			if (a == b) { 
			
				int length = line.size() % j;
				a.erase(0, length),	length = 8 - a.size();

				if (length <= 0) { for (int k = 0; k < 8; ++k) { cout << a[k]; } }
				else {

					cout << a;
					for (int k = 0; k < length; ++k) { cout << b[k%b.size()]; }
				}
					
				cout << "..." << endl;
				break;
			}
		}		
	}

	return 0;
}