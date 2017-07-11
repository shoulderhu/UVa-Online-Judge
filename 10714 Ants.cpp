#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int cases, l, n, pos, early, late;

	cin >> cases;

	for (int i = 0; i < cases; ++i) {

		cin >> l >> n >> pos;

		if (pos < l / 2) { early = pos, late = l - pos; }
		else { early = l - pos, late = pos; }
		
		for (int j = 1; j < n; ++j) {

			cin >> pos;

			if (pos < l / 2) { 
				
				early = max(early, pos), late = max(late, l - pos);
			}
			else { early = max(early, l-pos), late = max(late, pos); }
		}

		cout << early << " " << late << endl;
	}
	
	return 0;
}