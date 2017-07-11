#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pairs { int L, R; }Pair;

inline bool mySort1(struct pairs p1, struct pairs p2) { return p1.L < p2.L; }
inline bool mySort2(struct pairs p1, struct pairs p2) { return p1.R > p2.R; }

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace, M;	
	vector<struct pairs> Vector;
	vector<struct pairs> solution;

	cin >> kace;

	for (int i = 1; i <= kace; i++) {

		int m = 0;
		bool isConnected = true;
		Vector.clear(), solution.clear();

		if (i > 1) { cout << endl; }

		cin >> M;

		while (cin >> Pair.L >> Pair.R && !(Pair.L == 0 && Pair.R == 0)) { 
			
			Vector.push_back(Pair); 
		}

		sort(Vector.begin(), Vector.end(), mySort1);
				
		while (m < M) {
						
			vector<struct pairs> temp;

			while (Vector.empty() == false && Vector[0].L <= m) {

				temp.push_back(Vector[0]), Vector.erase(Vector.begin());
			}

			if (temp.empty() == false) {

				sort(temp.begin(), temp.end(), mySort2);
				solution.push_back(temp[0]);
				m = temp[0].R;
			}
			else { isConnected = false; break; }
		}
				
		if (isConnected == false) { cout << "0\n"; }
		else {

			cout << solution.size() << endl;

			for (int j = 0; j < solution.size(); j++) {

				cout << solution[j].L << " " << solution[j].R << endl;
			}
		}
	}

	return 0;
}