#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int K, E, kace = 0;
	struct excue {

		int time = 0;
		string line;
	};
	string key;
	stringstream ss;
	
	while (cin >> K >> E) {

		cin.ignore();
		
		int Max = 0;
		set<string> keyWord;
		vector<struct excue> Vector;

		for (int i = 1; i <= K; ++i) {

			cin >> key, cin.ignore();
			keyWord.insert(key);
		}
				
		for (int i = 1; i <= E; ++i) {

			struct excue sen;

			getline(cin, sen.line);
						
			string lineCpy = sen.line, word;
			transform(sen.line.begin(), sen.line.end(), lineCpy.begin(), ::tolower);

			for (int j = 0; j < sen.line.size(); ++j) {

				if (isalpha(lineCpy[j]) == 0) { lineCpy[j] = ' '; }
			}

			ss.clear(), ss << lineCpy;

			while (ss >> word) {

				if (keyWord.find(word) != keyWord.end()) { ++sen.time; }
			}

			Max = max(sen.time, Max), Vector.push_back(sen);
		}
				
		cout << "Excuse Set #" << ++kace << endl;
		
		for (auto iter = Vector.begin(); iter != Vector.end(); ++iter) {
			
			if (iter->time == Max) { cout << iter->line << endl; }
		}

		cout << endl;
	}

	return 0;
}
