#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, X, card[20], selection = 0;
		
	while (cin >> N >> X) {
		
		for (int i = 0; i < 20; ++i) { cin >> card[i]; }

		if (X >= N) { 
		
			cout << "Selection #" << ++selection << endl << "1";
			for (int i = 2; i <= N; ++i) { cout << " " << i; }			
		}
		else {
						
			bool isLucky = false;
			list<int> lottery;

			for (int i = 1; i <= N; ++i) { lottery.push_back(i); }

			for (int i = 0; i < 20 && isLucky == false; ++i) {

				int time = lottery.size() / card[i];
				auto iter = lottery.begin();

				for (int j = 1; j <= time; ++j) {

					iter = lottery.erase(next(iter, card[i] - 1));

					if (lottery.size() == X) {

						isLucky = true;
						break;
					}
				}
			}

			cout << "Selection #" << ++selection << endl << *lottery.begin();

			for (auto iter = ++lottery.begin(); iter != lottery.end(); ++iter) {

				cout << " " << *iter;
			}
		}

		cout << endl << endl;
	}

	return 0;
}