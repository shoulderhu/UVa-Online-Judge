#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct job { int time, fine, order; }Job;

bool mySort(struct job a, struct job b) {

	int fineA = a.time*b.fine, fineB = b.time*a.fine;

	if (fineA != fineB) { return fineA < fineB; }
	else { return a.order < b.order; }
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace, N;

	cin >> kace;

	for (int i = 1; i <= kace; ++i) {

		if (i > 1) { cout << endl; }

		vector<struct job> Vector;

		cin >> N;

		for (int j = 1; j <= N; ++j) {

			cin >> Job.time >> Job.fine;
			Job.order = j;
			Vector.push_back(Job);
		}

		sort(Vector.begin(), Vector.end(), mySort);

		for (int j = 0; j < N; ++j) {

			cout << Vector[j].order;
			if (j != N - 1) { cout << " "; }
		}

		cout << endl;
	}

	return 0;
}
