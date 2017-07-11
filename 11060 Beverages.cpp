#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, C = 0;
	struct node {

		string wine;
		unordered_set<string> set;
	}Node;
	string B1, B2;

	while (cin >> N) {

		vector<struct node> Vec;
		
		for (int i = 0; i < N; ++i) {

			cin >> Node.wine;
			Vec.push_back(Node);
		}

		cin >> M;

		for (int i = 0; i < M; ++i) {

			cin >> B1 >> B2;
			
			auto iter = find_if(Vec.begin(), Vec.end(), [&B2](struct node n) {
			
				return n.wine == B2;
			});

			iter->set.insert(B1);
		}

		cout << "Case #" << ++C << ": Dilbert should drink beverages in this order: ";

		while (Vec.size() != 0) {

			for (auto iter = Vec.begin(); iter != Vec.end(); ++iter) {
				
				if (iter->set.size() == 0) {

					string erase = iter->wine;
					Vec.erase(iter);

					cout << erase;
					if (Vec.size() != 0) { cout << " "; }

					for (auto jter = Vec.begin(); jter != Vec.end(); ++jter) {

						jter->set.erase(erase);
					}

					break;
				}			
			}
		}

		cout << "." << endl << endl;
	}

	return 0;
}