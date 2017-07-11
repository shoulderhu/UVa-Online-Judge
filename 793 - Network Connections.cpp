#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int Array[1000];

int getRoot(int v) {

	if (Array[v] == v) { return v; }
	else { return Array[v] = getRoot(Array[v]); }
}

int main() {

	int cases, C, Ci, Cj, I, J;
	char c;
	string pair;
	stringstream ss;

	cin >> cases, cin.ignore(), cin.ignore();

	for (int i = 0; i < cases; ++i) {

		if (i > 0) { cout << endl; }

		int success = 0, unsuccess = 0;

		cin >> C, cin.ignore();

		for (int j = 1; j <= C; ++j) { Array[j] = j; }

		while (getline(cin, pair) && pair != "") {

			ss.clear(), ss << pair, ss >> c >> Ci >> Cj;
			I = getRoot(Ci), J = getRoot(Cj);

			if (c == 'c') { Array[J] = I; }
			else { I == J ? ++success : ++unsuccess; }
		}

		cout << success << "," << unsuccess << endl;
	}

	return 0;
}
