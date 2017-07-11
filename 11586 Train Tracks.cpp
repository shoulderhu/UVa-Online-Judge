#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace;
	string line, track;
	stringstream ss;

	cin >> kace, cin.ignore();

	for (int i = 0; i < kace; ++i){

		getline(cin, line), ss.clear(), ss << line;

		int connector[2] = { 0, 0 };

		while (ss >> track){

			for (int j = 0; j < 2; ++j){

				track[j] == 'M' ? ++connector[0] : ++connector[1];
			}			
		}

		if (connector[0] == connector[1] && connector[0] != 1){

			cout << "LOOP" << endl;
		}
		else{ cout << "NO LOOP" << endl; }
	}

	return 0;
}