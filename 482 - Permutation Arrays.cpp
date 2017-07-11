#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int Cace, index;
	string line, value;
	stringstream sin;
	vector<int> Vector;
	map<int, string> Map;	

	Vector.reserve(1000000);	
	cin >> Cace, cin.ignore();
	
	for (int i = 0; i < Cace; ++i) {
				
		if (i > 0) { 
			
			cout << "\n";
			Vector.clear(), Map.clear();
		}
		
		cin.ignore();
		getline(cin, line);
		sin.clear(), sin << line;
		while (sin >> index) { Vector.push_back(index); }
		
		getline(cin, line);
		sin.clear(), sin << line;

		for (int i = 0; i < Vector.size(); ++i) {

			sin >> value, Map[Vector[i]] = value;
		}		

		for (auto iter = Map.begin(); iter != Map.end(); ++iter) {

			cout << iter->second << "\n";
		}
	}

	return 0;
}
