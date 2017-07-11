#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	string card, num;

	while (cin >> N && N != 0){

		vector<string> Card(N);
		deque<int> order;

		for (int i = 0; i < N; ++i){ order.push_back(i); }

		for (int i = 0; i < N; ++i){

			cin >> card >> num;

			for (int j = 0; j < num.size() - 1; ++j){

				order.push_back(order.front());
				order.pop_front();
			}

			Card[order.front()] = card, order.pop_front();
		}

		cout << Card[0];
		for (int i = 1; i < N; ++i){ cout << " " << Card[i]; }
		cout << endl;
	}
	
	return 0;
}