#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct dna {

	int sorted = 0;
	string line, lineCpy;
}DNA;

inline bool mySort(struct dna a, struct dna b) { return a.sorted < b.sorted; }

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int M, n, m;
	
	cin >> M;

	for (int i = 1; i <= M; ++i) {

		if (i > 1) { cout << endl; }

		cin >> n >> m;

		vector<struct dna> Vector;

		for (int j = 1; j <= m; ++j) {

			cin >> DNA.line;
			DNA.lineCpy = DNA.line, Vector.push_back(DNA);
		}

		for (auto iter = Vector.begin(); iter != Vector.end(); ++iter) {

			for (int j = 0; j < n - 1; ++j) {

				for (int k = 0; k < n - 1 - j; ++k) {

					if (iter->lineCpy[k] > iter->lineCpy[k + 1]) {

						swap(iter->lineCpy[k], iter->lineCpy[k + 1]);
						++iter->sorted;
					}
				}
			}
		}

		stable_sort(Vector.begin(), Vector.end(), mySort);

		for (auto iter = Vector.begin(); iter != Vector.end(); ++iter) {

			cout << iter->line << endl;
		}
	}
	
	return 0;
}