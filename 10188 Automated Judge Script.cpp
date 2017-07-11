#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool isPE(string s, string o) {

	for (int i = 0; i < s.size(); i++) {
		
		while (i < s.size() && isdigit(s[i]) == 0) { s.erase(i, 1); }
	}

	for (int i = 0; i < o.size(); i++) {

		while (i < o.size() && isdigit(o[i]) == 0) { o.erase(i, 1); }
	}

	return s == o;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, run = 0;
	string input, solution, output;
		
	while (cin >> n && n != 0) {
		
		cin.ignore(), solution.clear(), output.clear();
		
		for (int i = 1; i <= n; i++) {

			getline(cin, input);
			solution.append(input), solution.append("\n");
		}

		cin >> m, cin.ignore();

		for (int i = 1; i <= m; i++) {

			getline(cin, input);
			output.append(input), output.append("\n");
		}

		cout << "Run #" << ++run << ": ";

		if (solution == output) { cout << "Accepted\n"; }
		else if (isPE(solution, output) == true) { cout << "Presentation Error\n"; }
		else{ cout << "Wrong Answer\n"; }		
	}	

	return 0;
}