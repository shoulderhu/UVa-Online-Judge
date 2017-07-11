#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	int p[10000];
	bool isAntiarithmetic;
	string str;
	unordered_map<int, int> pos;
	
	while (cin >> str && str != "0") {
		
		str.pop_back();
		n = stoi(str, nullptr, 10);
		isAntiarithmetic = true;
		pos.clear();
				
		for (int i = 0; i < n; ++i) {

			cin >> p[i];
			pos[p[i]] = i;
		}
		
		for (int i = 0; i < n - 2; ++i) {

			for (int j = i + 1; j < n - 1; ++j) {
								 
				if (pos[p[j] + p[j] - p[i]] > j) {

					isAntiarithmetic = false;
					break;
				}
			}

			if (!isAntiarithmetic) { break; }
		}
	
		cout << (isAntiarithmetic ? "yes\n" : "no\n");
	}

	return 0;
}