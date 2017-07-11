#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, action;
	string instruction, temp[2];
	stringstream ss;
	vector<string> Vector;

	cin >> T, cin.ignore();

	for (int i = 1; i <= T; i++) {

		int x = 0;
		Vector.clear();

		cin >> n, cin.ignore();

		for (int j = 1; j <= n; j++) {

			getline(cin, instruction);
			Vector.push_back(instruction);

			while (instruction[0] == 'S') { 
				
				ss.clear(), ss << instruction, ss >> temp[0] >> temp[1] >> action;

				instruction = Vector[action - 1];
			}

			instruction == "LEFT" ? x-- : x++;
		}

		cout << x << endl;
	}

	return 0;
}