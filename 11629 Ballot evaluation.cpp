#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

inline bool isMoreThen(double left, int right) { return left > right; }

inline bool isLessThen(double left, int right) { return left < right; }

inline bool isEqual(double left, int right) { return left == right; }

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int p, g, guess = 0, right;
	bool isCorrect;
	double percentage;
	string name, line, item, COMP;
	map<string, int> result;

	cin >> p >> g, cin.ignore();

	for (int i = 1; i <= p; ++i) {

		cin >> name >> percentage, cin.ignore();
		result[name] = percentage * 10;
	}

	for (int i = 1; i <= g; ++i) {

		getline(cin, line);

		double left = 0;
		stringstream ss(line);
		ss >> item;

		left += result[item];

		while (ss >> item && item == "+") {

			ss >> item;
			left += result[item];			
		}

		COMP = item, ss >> right, right *= 10;

		if (COMP == "<") { isCorrect = isLessThen(left, right); }
		else if (COMP == ">") { isCorrect = isMoreThen(left, right); }
		else if (COMP == "<=") { isCorrect = isLessThen(left, right) || isEqual(left, right); }
		else if (COMP == ">=") { isCorrect = isMoreThen(left, right) || isEqual(left, right); }
		else if (COMP == "=") { isCorrect = isEqual(left, right); }

		cout << "Guess #" << ++guess << " was ";
		isCorrect == true ? cout << "correct.\n" : cout << "incorrect.\n";
	}

	return 0;
}