#include <iostream>
#include <vector>

using namespace std;

vector<int> vec(500000);

void mergeSort(vector<int>& Vec, int L, int R, long long int& op) {

	if (L < R) {

		int M = (L + R) / 2, l = L, r = M + 1, i = L;

		mergeSort(Vec, L, M, op);
		mergeSort(Vec, M + 1, R, op);
				
		while (l <= M && r <= R) {

			if (Vec[l] <= Vec[r]) { vec[i++] = Vec[l++]; }
			else {

				vec[i++] = Vec[r++];
				op += M - l + 1;
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

	int n, N;
	vector<int> Vec;
	Vec.reserve(500000);

	while (cin >> n && n != 0) {

		long long int op = 0;
		Vec.clear();

		for (int i = 1; i <= n; ++i) {

			cin >> N;
			Vec.push_back(N);
		}
		
		mergeSort(Vec, 0, Vec.size() - 1, op);
				
		cout << op << endl;
	}

	return 0;
}