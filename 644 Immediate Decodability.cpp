#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool rule(string a, string b) { 
	
	if (a.size() != b.size()) { return a.size() < b.size(); }
	else { return a < b; }
}

int main() {

	int kace = 0;
	string code;
	vector<string> set;
	
	while (cin >> code) {

		if (code != "9") { set.push_back(code); }
		else {

			sort(set.begin(), set.end(), rule);

			bool isDecodable = true;

			for (int i = 0; i < set.size(); i++) {

				for (int j = i + 1; j < set.size(); j++) {

					if (strncmp(set[i].c_str(), set[j].c_str(), set[i].size()) == 0) {

						isDecodable = false;
						break;
					}
				}

				if (isDecodable == false) { break; }
			}

			if (isDecodable == true) { printf("Set %d is immediately decodable\n", ++kace); }
			else { printf("Set %d is not immediately decodable\n", ++kace); }

			set.clear();
		}
	}

	return 0;
}