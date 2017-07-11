#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

int T, N;
string command;
set<int> a, b, cc;
vector<int> c(1000);
vector<int>::iterator iter;

int main() {
	
	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> N;

		stack<set<int>> Stack;
		map<set<int>, int> Map;
		
		for (int j = 0; j < N; ++j) {

			cin >> command;

			if (command[0] == 'P') { a.clear(), Stack.push(a); }
			else if (command[0] == 'D') { Stack.push(Stack.top()); }
			else if (command[0] == 'U') {

				a = Stack.top(), Stack.pop();
				b = Stack.top(), Stack.pop();
				iter = set_union(a.begin(), a.end(), b.begin(), b.end(), c.begin());
				cc.clear(), cc.insert(c.begin(), iter);
				Stack.push(cc);
			}
			else if (command[0] == 'I') {

				a = Stack.top(), Stack.pop();
				b = Stack.top(), Stack.pop();				
				iter = set_intersection(a.begin(), a.end(), b.begin(), b.end(), c.begin());
				cc.clear(), cc.insert(c.begin(), iter);
				Stack.push(cc);
			}
			else {

				a = Stack.top(), Stack.pop();
				b = Stack.top(), Stack.pop();
				if (Map.find(a) == Map.end()) { Map[a] = Map.size(); }				
				b.insert(Map[a]);
				Stack.push(b);
			}
			
			cout << Stack.top().size() << endl;
		}

		cout << "***" << endl;
	}

	return 0;
}