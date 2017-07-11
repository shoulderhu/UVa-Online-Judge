#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int P, C, kace = 0, x;
	char command;

	while (cin >> P >> C && P != 0 || C != 0) {

		list<int> Queue;

		if (P > 1000) { P = 1000; }

		for (int i = 1; i <= P; ++i) { Queue.push_back(i); }

		cout << "Case " << ++kace << ":" << endl;

		for (int i = 1; i <= C; ++i) {

			cin >> command;

			if (command == 'N') {

				cout << Queue.front() << endl;
				Queue.push_back(Queue.front()), Queue.pop_front();
			}
			else {

				cin >> x;
				auto iter = find(Queue.begin(), Queue.end(), x);
				if (iter != Queue.end()) { Queue.erase(iter); }
				Queue.push_front(x);
			}
		}
	}

	return 0;
}