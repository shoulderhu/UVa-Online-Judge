#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

	int i, j, n;
	string parenthesesString;
	stack <char> parentheses;

	scanf("%d", &n), getchar();

	for (i = 1; i <= n; i++) {

		getline(cin, parenthesesString);

		while (parentheses.empty() == false) { parentheses.pop(); }

		bool isCorrect = true;
			
		for (j = 0; j < parenthesesString.size(); j++) {

			if (parenthesesString[j] == '(' || parenthesesString[j] == '[') {

				parentheses.push(parenthesesString[j]);
			}
			else if (parenthesesString[j] == ')') {

				if (parentheses.empty() == true || parentheses.top() != '(') {
					
					isCorrect = false;
					break;
				}

				parentheses.pop();
			}
			else if (parenthesesString[j] == ']') {

				if (parentheses.empty() == true || parentheses.top() != '[') {

					isCorrect = false;
					break;
				}

				parentheses.pop();
			}			
		}

		if (parentheses.empty() == false) { isCorrect = false; }

		printf(isCorrect == true ? "Yes\n" : "No\n");
	}

	return 0;
}