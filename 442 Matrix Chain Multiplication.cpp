#include <iostream>
#include <cctype>
#include <string>
#include <map>
#include <stack>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	char name;
	struct matrix { int row, column; }Matrix;
	string str;
	map<char, struct matrix> Map;
	
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> name >> Matrix.row >> Matrix.column;
		Map[name] = Matrix;
	}

	while (cin >> str) {

		int time = 0;
		bool isError = false;
		stack<struct matrix> Stack;

		for (int i = 0; i < str.size(); i++) {

			if (str[i] == ')') {

				struct matrix temp = Stack.top();
				Stack.pop();

				if (Stack.top().column != temp.row) { isError = true; break; }
				else {

					Matrix.row = Stack.top().row, Matrix.column = temp.column;
					time += Matrix.row * Matrix.column * temp.row;
					Stack.pop(), Stack.push(Matrix);
				}				
			}
			else if (isalpha(str[i]) != 0) { Stack.push(Map[str[i]]); }
		}

		isError == true ? cout << "error\n" : cout << time << endl;	
	}

	return 0;
}
