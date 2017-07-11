#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, N, kace = 0, duration;
	
	cin >> T;

	for (int i = 1; i <= T; i++) {

		cin >> N;

		int Mile = 0, Juice = 0;

		for (int i = 1; i <= N; i++) {

			cin >> duration;
						
			Mile += (duration / 30 + 1) * 10;
			Juice += (duration / 60 + 1) * 15;						
		}

		cout << "Case " << ++kace;

		if (Mile > Juice) { cout  << ": Juice " << Juice << endl; }
		else if (Mile < Juice) { cout << ": Mile " << Mile << endl; }
		else{ cout << ": Mile Juice " << Mile << endl; }
	}

	return 0;
}
