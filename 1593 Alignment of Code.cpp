#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	string line, temp;
	stringstream ss;
	vector<int> length(1000, 0);
	vector<string> code;
	vector<vector<string>> alignCode;

	while (getline(cin, line)) {

		int p = 0;
		code.clear();

		ss.clear(), ss << line;
		
		while (ss >> temp) { 
			
			length[p] = max(length[p], (int)temp.size());
			p++, code.push_back(temp);			
		}

		alignCode.push_back(code);
	}

	for (auto iter = alignCode.begin(); iter != alignCode.end(); ++iter) {
						
		for (int i = 0; i < (*iter).size(); i++) {

			cout << (*iter)[i];

			if (i != (*iter).size() - 1) {

				for (int j = (length[i] - (*iter)[i].size()); j >= 0; j--) { cout << " "; }
			}			
		}

		cout << endl;
	}

	return 0;
}