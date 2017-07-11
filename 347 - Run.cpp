#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int R, e, pos, Case, d;
int runaround[9682416];
bool isDup;
bool ending[7], digit[10];
string r;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 9682415; i > 9; --i) {

		isDup = false, d = i;
		memset(digit, true, sizeof(digit));

		while (d > 0) {

			e = d % 10, d /= 10;
			if (digit[e] == false) { isDup = true; break; }
			digit[e] = false;
		}
								
		if (isDup) { 
			
			runaround[i] = runaround[i + 1];
			continue;
		}

		r = to_string(i);
		pos = 0, e = 0;
		memset(ending, true, sizeof(ending));

		while (ending[pos]) {

			ending[pos] = false, ++e;
			if ((pos = pos + (r[pos] - '0')) >= r.size()) { pos %= r.size(); }
		}

		if (pos == 0 && e == r.size()) {
						
			runaround[i] = i;			
		}
		else{ runaround[i] = runaround[i + 1]; }
	}

	while (cin >> R && R != 0) {
			
		cout << "Case " << ++Case << ": " << runaround[R] << '\n';
	}

	return 0;
}