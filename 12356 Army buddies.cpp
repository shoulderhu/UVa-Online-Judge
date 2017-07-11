#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int S, B, L, R;
	struct army { int left, right; }Army[100001];

	while (cin >> S >> B && S != 0 || B != 0) {
		
		for (int i = 1; i <= S; ++i) { Army[i].left = i - 1, Army[i].right = i + 1; }

		for (int i = 1; i <= B; ++i) {

			cin >> L >> R;

			if (Army[L].left == 0) { cout << "* "; }
			else { cout << Army[L].left << " "; }

			if (Army[R].right == S + 1) { cout << "*" << endl; }
			else { cout << Army[R].right << endl; }
						
			Army[Army[L].left].right = Army[R].right;
			Army[Army[R].right].left = Army[L].left;			
		}

		cout << "-" << endl;
	}

	return 0;
}