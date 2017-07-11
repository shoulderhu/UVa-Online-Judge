#include <iostream>
#include <tuple>
#include <set>
#include <deque>

using namespace std;

int N, n, press, Size;
bool isReach;
tuple<int, int, int, int> S, T, F, t, tmp;
set<tuple<int, int, int, int>> forbid, isVisit;
deque<tuple<int, int, int, int>> Q;

inline int left(int &g) {

	switch (g) {

	case 0: return 9; break;
	case 1: return 0; break;
	case 2: return 1; break;
	case 3: return 2; break;
	case 4: return 3; break;
	case 5: return 4; break; 
	case 6: return 5; break;
	case 7: return 6; break;
	case 8: return 7; break;
	case 9: return 8; break;
	}
}

inline int right(int &g) {

	switch (g) {

	case 0: return 1; break;
	case 1: return 2; break;
	case 2: return 3; break;
	case 3: return 4; break;
	case 4: return 5; break;
	case 5: return 6; break;
	case 6: return 7; break;
	case 7: return 8; break;
	case 8: return 9; break;
	case 9: return 0; break;
	}
}

inline void check() {

	if (isVisit.find(tmp) == isVisit.end() && 
		forbid.find(tmp) == forbid.end()) {

		Q.push_back(tmp), isVisit.insert(tmp);
	}
}

int main() {

	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i) {

		isVisit.clear(), forbid.clear(), Q.clear();

		cin >> get<0>(S) >> get<1>(S) >> get<2>(S) >> get<3>(S)
		    >> get<0>(T) >> get<1>(T) >> get<2>(T) >> get<3>(T)
		    >> n;

		isVisit.insert(S), Q.push_back(S);
		
		for (int j = 0; j < n; ++j) {

			cin >> get<0>(F) >> get<1>(F) >> get<2>(F) >> get<3>(F);
			forbid.insert(F);
		}

		press = -1, isReach = false;

		while (!Q.empty()) {

			Size = Q.size(), ++press;

			for (int j = 0; j < Size; ++j) {

				t = Q.front(), Q.pop_front();

				if (t == T) { isReach = true; break; }

				tmp = t, get<0>(tmp) = left(get<0>(tmp)), check();
				tmp = t, get<0>(tmp) = right(get<0>(tmp)), check();
				tmp = t, get<1>(tmp) = left(get<1>(tmp)), check();
				tmp = t, get<1>(tmp) = right(get<1>(tmp)), check();
				tmp = t, get<2>(tmp) = left(get<2>(tmp)), check();
				tmp = t, get<2>(tmp) = right(get<2>(tmp)), check();
				tmp = t, get<3>(tmp) = left(get<3>(tmp)), check();
				tmp = t, get<3>(tmp) = right(get<3>(tmp)), check();							
			}

			if (isReach) { break; }
		}

		if (isReach) { cout << press << endl; }
		else { cout << -1 << endl; }
	}

	return 0;
}