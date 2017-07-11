#include <iostream>
#include <string>
#include <set>

using namespace std;

set<char> Set = { 'a', 'e', 'i', 'o', 'u' };

bool isSame(string r, string a) {

	if (r.size() != a.size()) { return false; }
	
	for (int i = 0; i < r.size(); i++) {

		if (r[i] != a[i]) {
			
			if (Set.find(r[i]) == Set.end() || Set.find(a[i]) == Set.end()) {

				return false;
			}			
		}		
	}

	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string real, abstract;
	
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> real >> abstract;

		if (isSame(real, abstract) == true) { cout << "Yes\n"; }
		else { cout << "No\n"; }
	}

	return 0;
}