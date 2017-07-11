#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;

	while (cin >> s && s != ".") {

		int length = s.size();
		
		for (int i = 1; i <= length; ++i) {

			if (length%i != 0) { continue; }

			bool isSame = true;
			string S1 = s.substr(0, i);

			for (int j = i; j < length; j += i) {

				string S2 = s.substr(j, i);
				if (S1 != S2) { isSame = false;	break; }
			}

			if (isSame == true) { cout << length / i << endl; break; }
		}
	}

	return 0;
}