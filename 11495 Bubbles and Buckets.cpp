#include <iostream>
#include <vector>

using namespace std;

vector<int> vec(100000);

void mergeSort(vector<int>& Vec, int L, int R, long long int& move) {

	if (L < R) {

		int M = (L + R) / 2, l = L, r = M + 1, i = L;

		mergeSort(Vec, L, M, move);
		mergeSort(Vec, M + 1, R, move);

		while (l <= M && r <= R) {

			if (Vec[l] <= Vec[r]) { vec[i++] = Vec[l++]; }
			else {

				vec[i++] = Vec[r++];
				move += M - l + 1;
			}
		}

		while (l <= M) { vec[i++] = Vec[l++]; }
		while (r <= R) { vec[i++] = Vec[r++]; }

		for (i = L; i <= R; ++i) { Vec[i] = vec[i]; }
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, X;
	vector<int> Vec;
	Vec.reserve(100000);

	while (cin >> N && N != 0) {

		long long int move = 0;
		Vec.clear();

		for (int i = 1; i <= N; ++i) {

			cin >> X;
			Vec.push_back(X);
		}

		mergeSort(Vec, 0, Vec.size() - 1, move);
		move % 2 == 0 ? cout << "Carlos" << endl : cout << "Marcelo" << endl;
	}
	
	return 0;
}