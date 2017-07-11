#include <iostream>
#include <string>
#include <unordered_set> 
#include <unordered_map>
#include <queue>

using namespace std;

int main() {

	int cases, m, n;
	string A, B;

	cin >> cases;

	for (int i = 0; i < cases; ++i) {

		if (i > 0) { cout << endl; }

		cin >> m >> n;

		unordered_map<string, unordered_set<string>> road;
		unordered_map<string, bool> isVisit;

		for (int j = 0; j < m; ++j) {

			cin >> A >> B;
			road[A].insert(B), road[B].insert(A);
			isVisit[A], isVisit[B];
		}

		for (int j = 0; j < n; ++j) {

			cin >> A >> B;

			bool isLead = false;
			queue<string> Queue;
			unordered_map<string, string> Map;

			for (auto iter = isVisit.begin(); iter != isVisit.end(); ++iter) {

				iter->second =  false;
			}
			
			Queue.push(A), isVisit[A] = true;

			while (!Queue.empty()) {

				int Size = Queue.size();				
				string city = Queue.front();

				Queue.pop();

				for (int k = 0; k < Size; ++k) {

					for (auto iter = road[city].begin(); iter != road[city].end(); ++iter) {

						if (!isVisit[*iter]) {

							Map[*iter] = city;
							Queue.push(*iter);
							isVisit[*iter] = true;
						}

						if (B == *iter) { isLead = true; break; }
					}

					if (isLead) { break; }
				}

				if (isLead) { break; }
			}

			string route(B, 0, 1);

			while (B != A) {

				route.insert(route.begin(), Map[B][0]);
				B = Map[B];
			}

			cout << route << endl;
		}
	}

	return 0;
}