#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int map = 0;
	double d;
	string line, direction;

	while (cin >> line && line != "END") {

		int length = line.size() - 1;
		double x = 0, y = 0, constant = 0, sqrt2 = sqrt(2.0);

		for (int i = 0; i < length; ++i) {

			if (isdigit(line[i]) != 0) { constant = constant * 10 + (line[i] - '0'); }
			else if (line[i] == ',') { constant = 0; }
			else {

				if (isalpha(line[i + 1]) != 0) { direction = line.substr(i, 2), ++i; }
				else { direction = line.substr(i, 1); }

				if (direction == "N") { y += constant; }
				else if (direction == "NE") { x += constant / sqrt2, y += constant / sqrt2; }
				else if (direction == "E") { x += constant; }
				else if (direction == "SE") { x += constant / sqrt2, y -= constant / sqrt2; }
				else if (direction == "S") { y -= constant; }
				else if (direction == "SW") { x -= constant / sqrt2, y -= constant / sqrt2; }
				else if (direction == "W") { x -= constant; }
				else { x -= constant / sqrt2, y += constant / sqrt2; }
			}
		}
				
		d = sqrt(x*x + y*y);

		cout << "Map #" << ++map << endl << fixed << setprecision(3);
		cout << "The treasure is located at (" << x << "," << y << ")." << endl;
		cout << "The distance to the treasure is " << d << "." << endl;
		cout << endl;
	}

	return 0;
}