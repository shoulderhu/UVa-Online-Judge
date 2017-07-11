#include <iostream>
#include <cctype>
#include <string>
#include <stack>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string line;

	while (cin >> line) {

		bool isCorrect = true;
		stack<char> Stack;

		for (int i = line.size() - 1; i >= 0; --i) {

			if (isupper(line[i]) == 0) { Stack.push(line[i]); }
			else {

				if (line[i] == 'N') {

					if (Stack.size() < 1) { isCorrect = false; break; }
				}
				else {

					if (Stack.size() < 2) { isCorrect = false; break; }
					else { Stack.pop(); }
				}
			}
		}

		if (isCorrect == true && Stack.size() == 1) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	
	return 0;
}