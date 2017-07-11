#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string line, output, word;
	map<int, int> Map;

	while (getline(cin, line)) {
		
		if (line[0] == '#') {
			
			stringstream ss(output);

			while (ss >> word) { ++Map[word.size()]; }

			for (auto iter = Map.begin(); iter != Map.end(); ++iter) {

				cout << iter->first << " " << iter->second << endl;
			}

			cout << endl;
			Map.clear(), output = "";
		}
		else {
			
			bool isAdd;

			for (auto iter = line.begin(); iter != line.end(); isAdd == true ? ++iter : iter) {

				isAdd = true;

				if (isalpha(*iter) == 0 && *iter != ' ') {

					if (*iter == '\'') { iter = line.erase(iter), isAdd = false; }
					else if (*iter == '-') {
						
						if (iter != line.end() - 1) { iter = line.erase(iter), isAdd = false; }
					}
					else { *iter = ' '; }
				}
			}

			if (output.size() >= 1 && output[output.size() - 1] == '-') {
				
				output.erase(output.size() - 1, 1);
			}
			else { output += ' '; }			
			output += line;			
		}
	}

	return 0;
}