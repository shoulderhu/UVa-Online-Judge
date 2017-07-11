#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <stack>

using namespace std;

inline bool isPoped(char a, char b) { return b == '*' || b == '/' || a == '+' || a == '-'; }

void infixToPostfix(char infix, stack<char>& Stack) {

	if (isdigit(infix) != 0) { cout << infix; }
	else if (infix == '(') { Stack.push(infix); }
	else if (infix != ')') {

		while (Stack.top() != '(' && isPoped(infix, Stack.top()) == true) {

			cout << Stack.top();
			Stack.pop();
		}

		Stack.push(infix);
	}
	else {

		while (Stack.top() != '(') {

			cout << Stack.top();
			Stack.pop();
		}

		Stack.pop();
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace;
	string infix;
			
	cin >> kace, cin.ignore(), cin.ignore();

	for (int i = 1; i <= kace; ++i) {

		if (i > 1) { cout << endl; }
		
		stack<char> Stack;

		Stack.push('(');
		while (getline(cin, infix) && infix != "") { infixToPostfix(infix[0], Stack); }
		infixToPostfix(')', Stack);
				
		cout << endl;
	}

	return 0;
}