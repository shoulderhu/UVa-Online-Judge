#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string DNA;
vector<string> Vec;

void myFind(char symbol, size_t &pos) {

	string dna = DNA + DNA.substr(0, pos), str = dna.substr(pos);
	Vec.push_back(str);

	while ((pos = DNA.find(symbol, pos + 1)) != string::npos) {

		dna = DNA + DNA.substr(0, pos), str = dna.substr(pos);
		Vec.push_back(str);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	size_t pos;
	Vec.reserve(100);
	
	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> DNA;

		Vec.clear();
				
		if ((pos = DNA.find('A')) != string::npos) { myFind('A', pos); }
		else if ((pos = DNA.find('C')) != string::npos) { myFind('C', pos); }
		else if ((pos = DNA.find('G')) != string::npos) { myFind('G', pos); }
		else if ((pos = DNA.find('T')) != string::npos) { myFind('T', pos); }

		sort(Vec.begin(), Vec.end());
		cout << Vec[0] << endl;
	}

	return 0;
}