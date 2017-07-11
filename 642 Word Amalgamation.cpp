#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string word;
	map<string, set<string>> dictionary;

	while (cin >> word && word != "XXXXXX") {

		string wordCpy = word;

		sort(wordCpy.begin(), wordCpy.end());
		dictionary[wordCpy].insert(word);
	}

	while (cin >> word && word != "XXXXXX") {

		sort(word.begin(), word.end());

		if (dictionary.find(word) != dictionary.end()) {

			for (auto iter = dictionary[word].begin(); iter != dictionary[word].end(); ++iter) {

				cout << *iter << endl;
			}
		}
		else { cout << "NOT A VALID WORD" << endl; }

		cout << "******" << endl;
	}

	return 0;
}