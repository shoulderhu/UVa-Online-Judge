#include <iostream>
#include <string>
#include <deque>
#include <unordered_set>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int K, n;
	string name;

	cin >> K;

	for (int j = 0; j < K; ++j) {
		
		cin >> n;

		deque<string> original, desired;
		unordered_set<string> Set;

		cin.ignore(1024, '\n');

		for (int i = 0; i < n; ++i) {

			getline(cin, name);
			original.push_front(name);			
		}

		for (int i = 0; i < n; ++i) {

			getline(cin, name);
			desired.push_front(name);
		}

		for (int i = 0, k = 0; i < n; ++i, ++k) {

			if (k >= n) { 
				
				cout << desired[i] << endl;
				continue;
			}

			while (desired[i] != original[k]) {

				if (Set.find(desired[i]) != Set.end()) {

					cout << desired[i] << endl;
					original.push_back(desired[i]), Set.erase(desired[i]);
				}
				else{ Set.insert(original[k]); }	

				++k;
			}			
		}

		cout << endl;
	}

	return 0;
}