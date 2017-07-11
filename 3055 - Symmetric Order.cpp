#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int set = 0, n, l;
	string name, list[7];	

	while (cin >> n && n != 0) {
		
		l = -1;
		cout << "SET " << ++set << endl;

		for (int i = 0; i < n; ++i) {

			cin >> name;

			if (i % 2 == 0) { cout << name << endl; }
			else { list[++l] = name; }
		}

		for (int i = l; i >= 0; --i) {

			cout << list[i] << endl;
		}
	}
	
	return 0;
}