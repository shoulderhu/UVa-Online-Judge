#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	char w;
	string word;
	vector<unordered_map<char, int>> dictionary;

	while (cin >> word && word != "#") {

		unordered_map<char, int> Map;

		for (int i = 0; i < word.size(); ++i) { ++Map[word[i]]; }
		dictionary.push_back(Map);
	}

	cin.ignore(1024, '\n');

	while (getline(cin, word) && word != "#") {

		int form = 0;
		stringstream ss(word);
		unordered_map<char, int> puzzle;
		
		while(ss >> w){ ++puzzle[w]; }
						
		for (auto iter = dictionary.begin(); iter != dictionary.end(); ++iter) {

			bool isFormed = true;

			for (auto jter = (*iter).begin(); jter != (*iter).end(); ++jter) {

				if (jter->second > puzzle[jter->first]) {

					isFormed = false;
					break;
				}
			}

			if (isFormed == true) { ++form; }
		}
		
		cout << form << endl;
	}	

	return 0;
}