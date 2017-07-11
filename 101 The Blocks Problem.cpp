#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int n, Back;
vector<int> Stack(24);
vector<vector<int>> Block(24);

void RETURN(int &c) {

	while ((Back = Block[Stack[c]].back()) != c) {

		Stack[Back] = Back;
		Block[Back].push_back(Back);
		Block[Stack[c]].pop_back();
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, back;
	string command[2];
	
	cin >> n;	

	for (int i = 0; i < n; ++i) { 
		
		Stack[i] = i;
		Block[i].push_back(i);
	}

	while (cin >> command[0] && command[0] != "quit") {

		cin >> a >> command[1] >> b;

		if (a == b || Stack[a] == Stack[b]) { continue; }

		if (command[1] == "onto") { RETURN(b); }

		if (command[0] == "move") {
						
			RETURN(a);
			Block[Stack[a]].pop_back();
			Block[Stack[b]].push_back(a);
			Stack[a] = Stack[b];
		}
		else {
					
			deque<int> Queue;

			while ((Back = Block[Stack[a]].back()) != a) {

				Stack[Back] = Stack[b];
				Queue.push_front(Back);
				Block[Stack[a]].pop_back();
			}

			Queue.push_front(a), Block[Stack[a]].pop_back();
			Block[Stack[b]].insert(Block[Stack[b]].end(), Queue.begin(), Queue.end());
			Stack[a] = Stack[b];
		}
	}

	for (int i = 0; i < n; ++i, cout << endl) {

		cout << i << ":";
		for (int j = 0; j < Block[i].size(); ++j) { cout << " " << Block[i][j]; }
	}

	return 0;
}