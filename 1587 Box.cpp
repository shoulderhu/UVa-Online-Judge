#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int w, h;
map<pair<int, int>, int> pallet;
unordered_set<int> Set;

bool isPossible1() {

	for (auto iter = pallet.begin(); iter != pallet.end(); ++iter) {

		if (iter->second != 2) { return false; }
	}

	return Set.size() == 3;
}

bool isPossible2() {

	bool isTwo = false, isFour = false;

	for (auto iter = pallet.begin(); iter != pallet.end(); ++iter) {

		switch (iter->second) {

		case 2: isTwo = true; break;
		case 4: isFour = true; break;
		}	
	}

	return isTwo && isFour && Set.size() == 2;
}

inline bool isPossible3() { return Set.size() == 1; }

int main() {
	
	while (cin >> w >> h) {
		
		if (w > h) { swap(w, h); }
		pallet.clear(), ++pallet[{w, h}];
		Set.clear(), Set.insert(w), Set.insert(h);

		for (int i = 0; i < 5; ++i) {

			cin >> w >> h;
			if (w > h) { swap(w, h); }
			++pallet[{w, h}], Set.insert(w), Set.insert(h);
		}

		if (isPossible1() || isPossible2() || isPossible3()) {

			cout << "POSSIBLE" << endl;
		}
		else { cout << "IMPOSSIBLE" << endl; }
	}

	return 0;
}