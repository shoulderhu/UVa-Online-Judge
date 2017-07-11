#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {

	double n;	
	string name, song[] = { "Happy", "birthday", "to", "you",
		                    "Happy", "birthday", "to", "you", 
		                    "Happy", "birthday", "to", "Rujia", 
		                    "Happy", "birthday", "to", "you" };
	vector<string> people;
	
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> name;
		people.push_back(name);
	}

	for (int i = 1, k = 0; i <= ceil(n / 16); i++) {

		for (int j = 0; j < 16; j++, k++) {

			if (k == n) { k -= n; }
			
			cout << people[k] << ": " << song[j] << endl;
		}
	}

	return 0;
}
