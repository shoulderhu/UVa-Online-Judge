#include <iostream>
#include <set>
#include <unordered_set>
#include <iterator>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, B, ball;

	while (cin >> N >> B && N != 0 || B != 0){
		
		set<int> b;
		unordered_set<int> n;

		for (int i = 1; i <= N; ++i){ n.insert(i); }

		for (int i = 0; i < B; ++i){
		
			cin >> ball;
			b.insert(ball);
		}

		for (auto iter = b.begin(); iter != b.end(); ++iter){
		
			for (auto jter = next(iter, 1); jter != b.end(); ++jter){

				n.erase(*jter - *iter);
			}
		}

		n.size() == 0 ? cout << "Y" << endl : cout << "N" << endl;
	}

	return 0;
}