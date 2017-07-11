#include <iostream>
#include <string>

using namespace std;

int main() {

	int G;
	string str;

	while (cin >> G && G != 0) {

		cin >> str;

		int length = str.size() / G;

		for (int i = length - 1; i < str.size(); i += length) {

			for (int j = 0; j < length; ++j) { cout << str[i - j]; }			
		}

		cout << endl;
	}

	return 0;
}
