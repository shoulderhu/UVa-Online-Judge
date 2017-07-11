#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	long long int x, a;
	string line;
	
	while (cin >> x) {

		cin.ignore();
		getline(cin, line);

		long long int polynomial = 0;
		vector<long long int> Vector;
		stringstream ss(line);

		while (ss >> a) { Vector.push_back(a); }

		long long int n = 1, X = 1;

		for (int i = Vector.size() - 2; i >= 0; --i, X *= x, ++n) {

			polynomial += Vector[i] * n * X;
		}

		cout << polynomial << endl;
	}

	return 0;
}