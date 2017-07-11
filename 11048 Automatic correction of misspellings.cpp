#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isMissing(string word, string dictionary) {

	if (word.size() < dictionary.size()) { swap(word, dictionary); }

	for (int i = 0; i < word.size(); ++i) {

		string  w = word;

		w.erase(i, 1);
		if (w == dictionary) { return true; }
	}
	
	return false;
}

bool isWrong(string word, string dictionary) {

	int wrong = 1;

	for (int i = 0; i < word.size(); ++i) {

		if (word[i] != dictionary[i]) {
 
			if (--wrong < 0) { return false; }
		}
	}

	return true;
}

bool isUnordered(string word, string dictionary) {
	
	for (int i = 0; i < word.size() - 1; ++i) {

		string w = word;

		swap(w[i], w[i + 1]);
		if (w == dictionary) { return true; }
	}
	
	return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	string word;
	vector<string> dictionary;

	cin >> n;

	for (int i = 0; i < n; ++i) {

		cin >> word;
		dictionary.push_back(word);
	}

	cin >> q;

	for (int i = 0; i < q; ++i) {

		cin >> word;

		if (find(dictionary.begin(), dictionary.end(), word) != dictionary.end()) {

			cout << word << " is correct" << endl;
		}
		else {

			bool isMisspelling = false;

			for (int j = 0; j < dictionary.size(); ++j) {

				int letter = dictionary[j].size() - word.size();

				if (letter == 0) {

					if (isWrong(word, dictionary[j]) == true || isUnordered(word, dictionary[j]) == true) {

						cout << word << " is a misspelling of " << dictionary[j] << endl;
						isMisspelling = true;
						break;
					}					
				}
				else if (letter == 1 || letter == -1) {

					if (isMissing(word, dictionary[j]) == true) {

						cout << word << " is a misspelling of " << dictionary[j] << endl;
						isMisspelling = true;
						break;
					}
				}
			}

			if (isMisspelling == false) { cout << word << " is unknown" << endl; }
		}		
	}

	return 0;
}