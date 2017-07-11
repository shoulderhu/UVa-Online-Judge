#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int L, N;
	string sigular, plural;
	map<string, string> Map;

	cin >> L >> N;

	for (int i = 1; i <= L; ++i) { 
		
		cin >> sigular >> plural; 
		Map[sigular] = plural;	
	}

	for (int i = 1; i <= N; ++i) {

		cin >> sigular;
		
		if (Map.find(sigular) != Map.end()) {

			cout << Map[sigular] << endl;
		}
		else {

			char c2 = sigular[sigular.size() - 1], c1 = sigular[sigular.size() - 2];
			string s = sigular.substr(sigular.size() - 2, 2);

			if (c1 != 'a' && c1 != 'e' && c1 != 'i' && c1 != 'o' && c1 != 'u' && c2 == 'y') {

				sigular.erase(sigular.size() - 1, 1);
				cout << sigular << "ies" << endl;
			}
			else if (c2 == 'o' || c2 == 's' || c2 == 'x' || s == "ch" || s == "sh") {

				cout << sigular << "es" << endl;
			}
			else { cout << sigular << "s" << endl; }
		}		
	}

	return 0;
}