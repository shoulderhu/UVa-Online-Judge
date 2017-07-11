#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, n, t, m, nn, time;	
	int input[10000];
	bool bank;	
	struct car { int time, order; }Car;
	string b;
	queue<struct car> left, right;
	
	cin >> c;

	for (int i = 0; i < c; ++i) {

		if (i > 0) { cout << '\n'; }

		cin >> n >> t >> m;
				
		for (int j = 0; j < m; ++j) {

			cin >> Car.time >> b;
			Car.order = j;
			
			if (b[0] == 'l') { 
				
				left.push(Car); 
			}
			else { right.push(Car); }
		}
		
		time = 0, bank = true;

		while (!left.empty() || !right.empty()) {

			if (bank) {

				if (left.empty()) {

					if (time < right.front().time) {

						time = right.front().time + t;
					}
					else { time += t; }

					bank = false;
					continue;
				}

				if (time < left.front().time) {

					if (!right.empty() && left.front().time > right.front().time) {

						if (time > right.front().time) {

							time += t;
						}
						else { time = right.front().time + t; }

						bank = false;
						continue;
					}
					else { time = left.front().time; }
				}

				nn = 0;

				while (!left.empty() && left.front().time <= time && nn + 1 <= n) {

					input[left.front().order] = time + t;
					left.pop(), ++nn;
				}
			}
			else {

				if (right.empty()) {

					if (time < left.front().time) {

						time = left.front().time + t;
					}
					else { time += t; }

					bank = true;
					continue;
				}

				if (time < right.front().time) {

					if (!left.empty() && right.front().time > left.front().time) {

						if (time > left.front().time) {

							time += t;
						}
						else { time = left.front().time + t; }

						bank = true;
						continue;
					}
					else { time = right.front().time; }
				}

				nn = 0;

				while (!right.empty() && right.front().time <= time && nn + 1 <= n) {

					input[right.front().order] = time + t;
					right.pop(), ++nn;
				}
			}

			time += t, bank = !bank;
		}

		for (int j = 0; j < m; ++j) {

			cout << input[j] << '\n';
		}
	}

	return 0;
}