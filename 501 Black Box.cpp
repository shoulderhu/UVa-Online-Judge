#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int K, M, N, A, u;

	cin >> K;

	for (int i = 1; i <= K; ++i) {

		if (i > 1) { cout << endl; }

		cin >> M >> N;

		queue<int> blackBox;
		vector<int> solution;
		
		for (int j = 1; j <= M; ++j){
			
			cin >> A;
			blackBox.push(A);
		}
		
		for (int j = 0; j < N; ++j) {

			cin >> u;			

			while (solution.size() != u) {

				auto iter = lower_bound(solution.begin(), solution.end(), blackBox.front());
				solution.insert(iter, blackBox.front()), blackBox.pop();
			}
						
			cout << solution[j] << endl;
		}
	}

	return 0;
}