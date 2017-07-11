#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int size;
	string text;

	while (cin >> size >> text) {

		int length = text.size() - size + 1, max = 1;
		map<string, int> Map;

		for (int i = 0; i <= length; ++i) {

			string str = text.substr(i, size);

			++Map[str];
			if (Map[str] > max) { max = Map[str]; }
		}

		for (auto iter = Map.begin(); iter != Map.end(); ++iter) {

			if (iter->second == max) { cout << iter->first << endl; break; }
		}
	}
	
	return 0;
}