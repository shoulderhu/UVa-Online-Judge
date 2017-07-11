#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int L, U, R, RV[10], l, tmp, Size, Case = 0;
	deque<int> lock;
	
	while (cin >> L >> U >> R && !(L == 0 && U == 0 && R == 0)) {

		vector<bool> isVisit(10000, false);
		lock.clear(), lock.push_back(L);

		for (int i = 0; i < R; ++i) { cin >> RV[i]; }
		
		int press = 0;
		bool isUnlock = false;

		while (!lock.empty()) {

			Size = lock.size(), ++press;

			for (int i = 0; i < Size; ++i) {

				l = lock.front(), lock.pop_front();

				for (int j = 0; j < R; ++j) {

					tmp = (l + RV[j]) % 10000;					
					if (tmp == U) { isUnlock = true; break; }

					if (!isVisit[tmp]) {

						isVisit[tmp] = true;
						lock.push_back(tmp);
					}
				}
			}

			if(isUnlock) { break; }
		}

		cout << "Case " << ++Case << ": ";
		if (isUnlock) { cout << press << endl; }
		else { cout << "Permanently Locked" << endl; }
	}

	return 0;
}
