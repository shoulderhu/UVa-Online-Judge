#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, Q;
	string first, second;
	unordered_map<string, string> slogan;

	cin >> N, cin.ignore();

	for (int i = 0; i < N; ++i) {

		getline(cin, first), getline(cin, second);
		slogan[first] = second;
	}

	cin >> Q, cin.ignore();

	for (int i = 0; i < Q; ++i) {

		getline(cin, first);
		cout << slogan[first] << endl;
	}
	
	return 0;
}