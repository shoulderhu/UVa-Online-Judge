#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int x;
struct team {

	int ID;
	vector<int> queue;
}Team;
map<int, int> table;

bool myFind(struct team T) { return T.ID == table[x]; };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, element, num, scenario = 0;
	string command;

	while (cin >> t && t != 0) {
			
		vector<struct team> teamQueue;
		table.clear();

		for (int i = 1; i <= t; ++i) {

			cin >> num;

			for (int j = 1; j <= num; ++j) { 
				
				cin >> element;
				table[element] = i;
			}
		}

		cout << "Scenario #" << ++scenario << endl;

		while (cin >> command && command != "STOP") {

			if (command == "ENQUEUE") {

				cin >> x;

				auto iter = find_if(teamQueue.begin(), teamQueue.end(), myFind);
				
				if (iter != teamQueue.end()) { iter->queue.push_back(x); }
				else{
				
					struct team temp;
					temp.ID = table[x], temp.queue.push_back(x);
					teamQueue.push_back(temp);
				}
			}
			else {
				
				cout << teamQueue[0].queue[0] << endl;				
				if (teamQueue[0].queue.size() == 1) { teamQueue.erase(teamQueue.begin()); }
				else{ teamQueue[0].queue.erase(teamQueue[0].queue.begin()); }
			}
		}		

		cout << endl;
	}

	return 0;
}