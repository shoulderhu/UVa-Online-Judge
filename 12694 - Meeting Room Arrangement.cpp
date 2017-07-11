#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n, s, f;

	cin >> n;

	for (int i = 0; i < n; ++i) {

		vector<pair<int, int>> event;
		
		while (cin >> s >> f && !(s == 0 && f == 0)) {

			event.push_back({ f, s });
		}

		sort(event.begin(), event.end());

		int events = 0, pos = 0;

		for (int j = 0; j < event.size(); ++j) {

			if (pos <= event[j].second) {

				++events, pos = event[j].first;
			}
		}

		cout << events << endl;
	}
	
	return 0;
}