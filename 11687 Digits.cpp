#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string x0, x1;
	
	while (cin >> x0 && x0 != "END") {
		
		for (int i = 1; ;i++) {
			
			x1 = to_string(x0.size());

			if (x0 != x1) { x0 = x1; }
			else { cout << i << endl; break; }
		}
	}

	return 0;
}
