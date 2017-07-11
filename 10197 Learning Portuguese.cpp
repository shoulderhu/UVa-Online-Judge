#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	unsigned char o = 243;
	bool isBL = false;
	string v1, v2;
	
	while (cin >> v1 >> v2) {

		if (!isBL) { isBL = true; }
		else { cout << endl; }

		cout << v1 << " (to " << v2 << ")" << endl;

		if (v1.size() < 2 || (v1.compare(v1.size() - 2, 2, "ar") 
			              &&  v1.compare(v1.size() - 2, 2, "er")
						  &&  v1.compare(v1.size() - 2, 2, "ir"))) {

			cout << "Unknown conjugation" << endl;
			continue;
		}
		
		char tv = v1[v1.size() - 2];
		string root = v1.substr(0, v1.size() - 2);

		cout << "eu        " << root << "o" << endl;

		cout << "tu        " << root;
		tv == 'i' ? cout << "es" << endl : cout << tv << "s" << endl;

		cout << "ele/ela   " << root;
		tv == 'i' ? cout << "e" << endl : cout << tv << endl;
		
		cout << "n" << o << "s       " << root << tv << "mos" << endl;
		
		cout << "v" << o << "s       " << root << tv;
		tv == 'i' ? cout << "s" << endl : cout << "is" << endl;

		cout << "eles/elas " << root;
		tv == 'i' ? cout << "em" << endl : cout << tv << "m" << endl;
	}

	return 0;
}