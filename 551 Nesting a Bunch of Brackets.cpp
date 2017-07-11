#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string line;
	map<char, char> bracket = { { ')', '(' }, {']', '['}, {'}', '{'}, {'>', '<'} };

	while (getline(cin, line)) {

		int position = -1, asterisk = 0;
		stack<char> Stack;

		for (int i = 0; i < line.size(); ++i) {

			if (line[i] == '(') {

				if (line[i + 1] == '*') { Stack.push('*'), ++i, ++asterisk; }
				else { Stack.push('('); }
			}
			else if (line[i] == '[' || line[i] == '{' || line[i] == '<') { Stack.push(line[i]); }
			else if (line[i] == '*') { 
				
				if (line[i + 1] == ')') { 
					
					if (Stack.empty() == true || Stack.top() != '*') {
						
						position = i + 1 - asterisk;
						break;
					}
					else { ++i, ++asterisk, Stack.pop(); }
				}				
			}
			else if (line[i] == ')' || line[i] == ']' || line[i] == '}' || line[i] == '>') {

				if (Stack.empty() == true || Stack.top() != bracket[line[i]]) {
					
					position = i + 1 - asterisk; 
					break; 
				}
				else { Stack.pop(); }
			}			
		}

		if (position == -1) {

			if (Stack.empty() == true) { cout << "YES" << endl; }
			else { cout << "NO " << line.size() + 1 - asterisk << endl; }
		}
		else { cout << "NO " << position << endl; }		
	}

	return 0;
}
