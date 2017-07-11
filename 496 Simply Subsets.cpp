#include <iostream>
#include <sstream>
#include <string>
#include <set>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int element;
	string line;
	stringstream ss;

	while (getline(cin, line)) {

		set<int> A, B;

		ss.clear(), ss << line;
		while (ss >> element) { A.insert(element); }

		getline(cin, line);
		ss.clear(), ss << line;
		while (ss >> element) { B.insert(element); }

		int Alength = A.size(), Blength = B.size();

		for (auto iter = A.begin(); iter != A.end(); ) {

			if (B.find(*iter) != B.end()) { B.erase(*iter), A.erase(iter++); }
			else { ++iter; }
		}

		if (A.empty() == true) { 
			
			if (B.empty() == true) { cout << "A equals B" << endl; }
			else { cout << "A is a proper subset of B" << endl; }
		}
		else if (B.empty() == true) { cout << "B is a proper subset of A" << endl; }
		else if (A.size() == Alength && B.size() == Blength) {
		
			cout << "A and B are disjoint" << endl;
		}
		else { cout << "I'm confused!" << endl; }
	}
	
	return 0;
}