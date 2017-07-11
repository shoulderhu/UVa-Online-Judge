#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int num, kace;
	string word;
	
	cin >> kace;

	for (int i = 1; i <= kace; ++i) {

		if (i > 1) { cout << endl; }

		cin >> num;

		map<string, vector<string>> anagram;

		for (int j = 1; j <= num; ++j) {

			cin >> word;
			string wordCpy = word;
			sort(wordCpy.begin(), wordCpy.end());
			anagram[wordCpy].push_back(word);
		}

		while (cin >> word && word != "END") {
			
			cout << "Anagrams for: " << word << endl;

			string wordCpy = word;
			sort(wordCpy.begin(), wordCpy.end());

			if (anagram[wordCpy].empty() == true) { cout << "No anagrams for: " << word << endl; }
			else {

				for (int j = 0; j < anagram[wordCpy].size(); ++j) {

					cout << setw(3) << j + 1 << ") " << anagram[wordCpy][j] << endl;
				}
			}
		}
	}
	
	return 0;
}
