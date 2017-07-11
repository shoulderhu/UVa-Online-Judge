#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int Array[30001];

int getRoot(int v) {

	if (Array[v] == v) { return v; }
	else { return Array[v] = getRoot(Array[v]); }
}

int main() {

	int N, M, cases, A, B, a, b;

	cin >> cases;

	for (int i = 0; i < cases; ++i) {

		cin >> N >> M;

		for (int i = 1; i <= N; ++i) { Array[i] = i; }

		for (int j = 0; j < M; ++j) {

			cin >> A >> B;
			a = getRoot(A), b = getRoot(B);
			Array[b] = a;
		}

		int people = 0;
		unordered_map<int, int> Map;

		for (int i = 1; i <= N; ++i) {

			people = max(people, ++Map[getRoot(i)]);
		}

		cout << people << endl;
	}

	return 0;
}
