#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string line, encrypted, word;
	stringstream ss;

	cin >> n, cin.ignore();

	for (int i = 0; i < n; ++i) {

		string possible;

		getline(cin, line), ss.clear(), ss << line;
		cin >> word, cin.ignore();

		while (ss >> encrypted) {
			
			if (word.size() == encrypted.size()) {

				int k = encrypted[0] - word[0];
				bool isPossible = true;
				
				if (k < 0) { k += 26; }

				for (int j = 1; j < word.size(); ++j) {

					int temp = encrypted[j] - word[j];

					if (temp < 0) { temp += 26; }

					if (temp != k) {

						isPossible = false;
						break;
					}
				}

				if (isPossible == true) { possible += (char)(97 + k); }
			}
		}

		sort(possible.begin(), possible.end());
		cout << possible << endl;
	}

	return 0;
}