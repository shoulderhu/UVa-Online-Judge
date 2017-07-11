#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int b, s, n, m, MAX, begin, end, longest, start;

	cin >> b;

	for (int i = 1; i <= b; ++i) {

		cin >> s;
		--s, MAX = 0, m = 0, start = 1;

		for (int j = 0; j < s; ++j) {

			cin >> n;
			
			if ((m += n) < 0) {

				m = 0;
				start = j + 2;
				continue;
			}

			if (m > MAX) {

				MAX = m;
				begin = start, end = j + 2;
				longest = end - begin;
			}
			else if (m == MAX && j + 2 - start > longest) {

				begin = start, end = j + 2;
				longest = end - begin;				
			}
		}
		
		if (MAX != 0) {

			cout << "The nicest part of route " << i << " is between stops " 
				 << begin << " and " << end << endl;
		}
		else { cout << "Route " << i << " has no nice parts" << endl; }	
	}

	return 0;
}