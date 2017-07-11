#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, M, x, y, w, n;
bool isBL = false;
tuple<int, int, int> t;
vector<int> Vec;
vector<tuple<int, int, int>> line;

inline int getRoot(int l) {

	if (Vec[l] == l) { return l; }
	else { return Vec[l] = getRoot(Vec[l]); }	
}

int main() {

	ios::sync_with_stdio(false);
	
	while (cin >> N) {

		if (!isBL) { isBL = true; }
		else { 
			
			cout << endl;
			Vec.clear(), line.clear();
		}

		int original = 0, New = 0;

		for (int i = 0; i <= N; ++i) { Vec.push_back(i); }

		for (int i = 1; i < N; ++i) {

			cin >> x >> y >> w;
			original += w;
		}

		cin >> K;

		for (int i = 0; i < K; ++i) {

			cin >> get<0>(t) >> get<1>(t) >> get<2>(t);
			line.push_back(t);
		}

		cin >> M;

		for (int i = 0; i < M; ++i) {

			cin >> get<0>(t) >> get<1>(t) >> get<2>(t);
			line.push_back(t);
		}

		sort(line.begin(), line.end(), 
			 [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
		
			return get<2>(a) < get<2>(b);
		});

		M += K, n = 0;

		for (int i = 0; i < M && n < N; ++i) {

			get<0>(line[i]) = getRoot(get<0>(line[i]));
			get<1>(line[i]) = getRoot(get<1>(line[i]));

			if (get<0>(line[i]) != get<1>(line[i])) {

				New += get<2>(line[i]), ++n;
				Vec[get<1>(line[i])] = get<0>(line[i]);
			}
		}

		cout << original << endl << New << endl;
	}

	return 0;
}