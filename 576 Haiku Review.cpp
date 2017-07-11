#include <iostream>
#include <string>

using namespace std;

inline bool isVowel(char c) {

	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int syllables(string sen) {

	int vowel = 0;

	for (int i = 0; i < sen.size(); ++i) {

		if (isVowel(sen[i]) == true && (i - 1 == -1 || isVowel(sen[i - 1]) == false) ) {

			++vowel;
		}
	}

	return vowel;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string line;

	while (getline(cin, line) && line != "e/o/i") {

		size_t pos1 = line.find('/'), pos2 = line.find('/', pos1 + 1);
		string first = line.substr(0, pos1),
		       second = line.substr(pos1 + 1, pos2 - pos1 - 1),
			   third = line.substr(pos2 + 1, line.size() - pos2 - 1);

		if (syllables(first) == 5) {

			if (syllables(second) == 7) {

				if (syllables(third) == 5) {

					cout << "Y" << endl;
				}
				else { cout << "3" << endl; }
			}
			else { cout << "2" << endl; }
		}
		else { cout << "1" << endl; }
	}

	return 0;
}