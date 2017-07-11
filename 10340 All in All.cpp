#include <iostream>
#include <string>

using namespace std;

int main() {

	int i;
	string s, t;

	while (cin >> s >> t) {

		int j = 0;
		bool isSub = true;

		for (i = 0; i < s.size(); i++, j++) {

			while (s[i] != t[j]) {

				j++;
				if (j>t.size() - 1) {

					printf("No\n");
					isSub = false;
					break;
				}
			}
						
			if (isSub == false) { break; }
		}

		if (isSub == true) { printf("Yes\n"); }
	}

	return 0;
}