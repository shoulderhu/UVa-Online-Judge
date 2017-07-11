#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, N, fib[46], n;
	string line;
	map<int, int> Map;	
	fib[1] = 1, fib[2] = 2, Map[1] = 1, Map[2] = 2;

	for (int i = 3; i < 46; ++i) {

		fib[i] = fib[i - 1] + fib[i - 2];
		Map[fib[i]] = i;
	}
	
	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> N;

		int pos = 0, end = 0;
		vector<char> decryptedText(101, ' ');
		vector<int> Vector;

		for (int j = 1; j <= N; ++j) {

			cin >> n;
			Vector.push_back(n);
		}

		cin.ignore(1024, '\n'),	getline(cin, line);

		for (auto iter = Vector.begin(); iter != Vector.end(); ++iter, ++pos) {

			while (isupper(line[pos]) == 0) { ++pos; }
			decryptedText[Map[*iter]] = line[pos];
			if (Map[*iter] > end) { end = Map[*iter]; }
		}

		for (int j = 1; j <= end; ++j) { cout << decryptedText[j]; }

		cout << endl;
	}

	return 0;
}