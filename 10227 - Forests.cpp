#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

int main() {

	int cases, P, T, Pi, Pj;
	string pair;
	stringstream ss;
	unordered_map<int, set<int>> Map;

	cin >> cases, cin.ignore();

	for (int i = 0; i < cases; ++i) {

		if (i > 0) { 
			
			cout << endl; 
			Map.clear();
		}

		cin >> P >> T, cin.ignore();
		
		while (getline(cin, pair) && pair != "") {

			ss.clear(), ss << pair, ss >> Pi >> Pj;
			Map[Pi].insert(Pj);
		}

		set<set<int>> Set;

		for (int j = 1; j <= P; ++j) { Set.insert(Map[j]); }		
		cout << Set.size() << endl;
	}

	return 0;
}
