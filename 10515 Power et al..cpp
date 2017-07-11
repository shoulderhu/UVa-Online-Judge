#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string m, n;
	map<int, map<int, int>> Map;
	
	Map[2][0] = 6, Map[2][1] = 2, Map[2][2] = 4, Map[2][3] = 8;
	Map[3][0] = 1, Map[3][1] = 3, Map[3][2] = 9, Map[3][3] = 7;
	Map[4][0] = 6, Map[4][1] = 4;
	Map[7][0] = 1, Map[7][1] = 7, Map[7][2] = 9, Map[7][3] = 3;
	Map[8][0] = 6, Map[8][1] = 8, Map[8][2] = 4, Map[8][3] = 2;
	Map[9][0] = 1, Map[9][1] = 9;

	while (cin >> m >> n && !(m == "0" && n == "0")) {

		char end = m[m.size() - 1];

		if (n == "0") { cout << 1 << endl; }
		else if (end == '0' || end == '1' || end == '5' || end == '6') {
			
			cout << end << endl; 
		}
		else {
			
			int mod = Map[end - '0'].size();
			long long int value = 1;

			for (int i = 0; i < n.size(); ++i) { 
				
				value = (value * 10 + (n[i] - '0')) % mod;
			}

			cout << Map[end - '0'][value] << endl;
		}
	}

	return 0;
}