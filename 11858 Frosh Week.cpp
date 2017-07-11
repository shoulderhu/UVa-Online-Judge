#include <iostream>
#include <vector>

using namespace std;

vector<int> vec(1000000);

void mergeSort(vector<int>& Vec, int L, int R, long long int& swap) {

	if (L < R) {

		int M = (L + R) / 2, l = L, r = M + 1, i = L;

		mergeSort(Vec, L, M, swap);
		mergeSort(Vec, M + 1, R, swap);

		while (l <= M && r <= R) {

			if (Vec[l] <= Vec[r]) { vec[i++] = Vec[l++]; }
			else {

				vec[i++] = Vec[r++];
				swap += M - l + 1;
			}
		}

		while(l <= M){ vec[i++] = Vec[l++]; }
		while(r <= R){ vec[i++] = Vec[r++]; }

		for (i = L; i <= R; ++i) { Vec[i] = vec[i]; }
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, N;
	vector<int> Vec;
	Vec.reserve(1000000);

	while (cin >> n) {

		long long int swap = 0;
		Vec.clear();

		for (int i = 1; i <= n; ++i) {

			cin >> N;
			Vec.push_back(N);
		}

		mergeSort(Vec, 0, Vec.size() - 1, swap);

		cout << swap << endl;
	}

	return 0;
}