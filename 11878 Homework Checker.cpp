#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int correct = 0;
	string line;

	while (cin >> line) {

		int a = 0, b = 0, c = 0;
		char operation;
		bool isQuestion = true, isCorrect = false;

		for (int i = 0; i < line.size(); ++i) {

			while (line[i] != '+' && line[i] != '-') { 
				
				a = a * 10 + (line[i] - '0'), ++i; 
			}

			operation = line[i];
			++i;

			while (line[i] != '=') { 
				
				b = b * 10 + (line[i] - '0'), ++i;			
			}

			++i;

			while (line[i] != '?' && i < line.size()) { 
				
				c = c * 10 + (line[i] - '0'), ++i;
				isQuestion = false;
			}
		}

		if (isQuestion == false) {

			switch (operation) {

			case '+': if (a + b == c) { isCorrect = true; } break;
			case '-': if (a - b == c) { isCorrect = true; } break;
			}

			if (isCorrect == true) { ++correct; }
		}		
	}

	cout << correct << endl;

	return 0;
}
