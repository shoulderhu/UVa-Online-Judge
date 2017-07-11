#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, char> Map;

char getRoot(char &v) {

	if (Map[v] == v) { return v; }
	else { return Map[v] = getRoot(Map[v]); }
}

int main() {

	int cases;
	char node, X, Y;
	string pair;

	cin >> cases, cin.ignore(), cin.ignore();

	for (int i = 0; i < cases; ++i) {

		if (i > 0) {

			cout << endl;
			Map.clear();
		}

		cin >> node, cin.ignore();

		for (int j = 'A'; j <= node; ++j) { Map[j] = j; }

		while (getline(cin, pair) && pair != "") {

			X = getRoot(pair[0]), Y = getRoot(pair[1]);
			Map[Y] = X;
		}

		int subgraph = 0;

		for (auto iter = Map.begin(); iter != Map.end(); ++iter) {

			if (iter->first == iter->second) { ++subgraph; }
		}

		cout << subgraph << endl;
	}

	return 0;
}
