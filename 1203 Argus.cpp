#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct registers { int query, period; }Register;

struct mySort {

	bool operator()(struct registers& a, struct registers& b) {

		if (a.period != b.period) { return a.period > b.period; }
		else { return a.query > b.query; }
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int K;
	string word;
	vector<struct registers> Vec;
	priority_queue<struct registers, vector<struct registers>, mySort> Argus;

	while (cin >> word && word != "#") {

		cin >> Register.query >> Register.period;
		Vec.push_back(Register);
	}

	cin >> K;

	for (int i = 1; i <= K; ++i) {

		for (auto iter = Vec.begin(); iter != Vec.end(); ++iter) {

			struct registers temp = *iter;
			temp.period *= i, Argus.push(temp);
		}

		cout << Argus.top().query << endl;
		Argus.pop();
	}

	return 0;
}