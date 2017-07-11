#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, N, M, element;
	
	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> N >> M;

		int remove = 0;
		unordered_multiset<int> n, m;
		unordered_multiset<int>::iterator jter;

		for (int j = 0; j < N; ++j) {

			cin >> element;
			n.insert(element);
		}

		for (int j = 0; j < M; ++j) {

			cin >> element;
			m.insert(element);
		}

		for (auto iter = n.begin(); iter != n.end(); ++iter) {
			
			if ((jter = m.find(*iter)) != m.end()) { m.erase(jter); }
			else { ++remove; }
		}
		
		cout << remove + m.size() << endl;
	}

	return 0;
}