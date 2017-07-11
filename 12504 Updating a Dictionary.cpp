#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	char sign[3] = { '+', '-', '*' };
	string line, key, value;
	stringstream ss;	
	map<char, vector<string>> update;
	map<string, string> dictionary[2];
	map<string, string>::iterator temp;

	cin >> T, cin.ignore();

	for (int i = 1; i <= T; i++) {

		dictionary[0].clear(), dictionary[1].clear(), update.clear();

		for (int j = 0; j < 2; j++) {

			cin >> line, cin.ignore();

			for (int k = 0; k < line.size(); k++) {

				if (line[k] == '{' || line[k] == ':' || line[k] == ',' || line[k] == '}') { 
					
					line[k] = ' '; 
				}
			}

			ss.clear(), ss << line;

			while (ss >> key >> value) { dictionary[j][key] = value; }			
		}
		
		for (auto iter = dictionary[1].begin(); iter != dictionary[1].end(); ++iter) {

			if ((temp = dictionary[0].find(iter->first)) != dictionary[0].end()) {

				if (temp->second != iter->second) {

					update[sign[2]].push_back(iter->first);
				}

				dictionary[0].erase(temp);
			}
			else { update[sign[0]].push_back(iter->first); }
		}

		for (auto iter = dictionary[0].begin(); iter != dictionary[0].end(); ++iter) {

			update[sign[1]].push_back(iter->first);			
		}
		
		bool isChange = false;

		for (int i = 0; i < 3; i++) {
			
			if (update[sign[i]].size()>0) {

				isChange = true;

				sort(update[sign[i]].begin(), update[sign[i]].end());

				cout << sign[i];

				for (auto iter = update[sign[i]].begin(); iter != update[sign[i]].end(); ++iter) {

					cout << *iter;

					if (iter != update[sign[i]].end() - 1) { cout << ","; }
				}

				cout << endl;
			}
		}

		if (isChange == false) { cout << "No changes\n"; }

		cout << endl;
	}

	return 0;
}