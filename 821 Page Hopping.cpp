#include <iostream>
#include <iomanip>
#include <set>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	
	int a, b, page[101][101], kace = 0;

	while (cin >> a >> b && !(a == 0 && b == 0)) {
		
		for (int i = 1; i < 101; ++i) {

			for (int j = 1; j < 101; ++j) {

				if (i == j) { page[i][j] = 0; }
				else { page[i][j] = 100; }
			}
		}

		int sum = 0, pair = 0;
		set<int> node;
		node.insert(a), node.insert(b), page[a][b] = 1;

		while (cin >> a >> b && !(a == 0 && b == 0)) {

			node.insert(a), node.insert(b),	page[a][b] = 1;
		}

		for (auto iter = node.begin(); iter != node.end(); ++iter) {

			for (auto jter = node.begin(); jter != node.end(); ++jter) {

				for (auto kter = node.begin(); kter != node.end(); ++kter) {

					if (page[*jter][*kter] > page[*jter][*iter] + page[*iter][*kter]) {

						page[*jter][*kter] = page[*jter][*iter] + page[*iter][*kter];						
					}
				}
			}
		}

		for (auto iter = node.begin(); iter != node.end(); ++iter) {

			for (auto jter = node.begin(); jter != node.end(); ++jter) {

				if (page[*iter][*jter] != 100 && page[*iter][*jter] != 0) { 
					
					++pair, sum += page[*iter][*jter];
				}
			}
		}
				
		cout << "Case " << ++kace << ": average length between pages = " << fixed 
			 << setprecision(3) << (double)sum / pair << " clicks" << endl;
	}

	return 0;
}
