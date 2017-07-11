#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	struct keyboard {

		int line = 0;
		set<char> Set = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
			              'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
			              'w', 'x', 'y', 'z' };
	};
	string line, broken;	
	vector<struct keyboard> Vec;

	while (getline(cin, broken) && broken != "finish") {
			
		struct keyboard Keyboard;				
		transform(broken.begin(), broken.end(), broken.begin(), ::tolower);

		for (int i = 0; i < broken.size(); ++i) {

			Keyboard.Set.erase(broken[i]);
		}

		while (getline(cin, line) && line != "END") {

			bool isPrintable = true;
			transform(line.begin(), line.end(), line.begin(), ::tolower);

			for (int i = 0; i < broken.size(); ++i) {

				if (line.find(broken[i]) != string::npos) {

					isPrintable = false;
					break;
				}
			}

			if (isPrintable == true) {

				++Keyboard.line;

				for (int i = 0; i < line.size(); ++i) {

					if (isalpha(line[i]) != 0) { Keyboard.Set.erase(line[i]); }
				}
			}
		}
		
		if (broken.find('e') == string::npos && 
			broken.find('n') == string::npos &&
			broken.find('d') == string::npos) {

			++Keyboard.line;
			Keyboard.Set.erase('e');
			Keyboard.Set.erase('n');
			Keyboard.Set.erase('d');
		}
		
		Vec.push_back(Keyboard);
	}

	cout << "+----------+----------------+-----------------------------+" << endl;
	cout << "| Keyboard | # of printable | Additionally, the following |" << endl;
	cout << "|          |      lines     |  letter keys can be broken  |" << endl;
	cout << "+----------+----------------+-----------------------------+" << endl;

	for (int i = 0; i < Vec.size(); ++i) {

		cout << "|   " << setw(3) << i + 1 << "    |      " << 
			              setw(3) << Vec[i].line << "       | ";
		
		for (auto iter = Vec[i].Set.begin(); iter != Vec[i].Set.end(); ++iter) {

			cout << *iter;
		}

		for (int j = Vec[i].Set.size() + 2; j < 30; ++j) { cout << " "; }

		cout << "|" << endl;
		cout << "+----------+----------------+-----------------------------+" << endl;
	}

	return 0;
}