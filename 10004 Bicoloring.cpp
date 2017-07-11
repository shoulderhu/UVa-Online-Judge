#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

struct node {

	int color = 0;
	set<int> edge;
};

int main() {

    ios::sync_with_stdio(false);
	
	int n, l, a, b;
	map<int, struct node> Map;

	while (cin >> n && n != 0) {

		Map.clear();

		cin >> l;

		for (int i = 1; i <= l; i++) {

			cin >> a >> b;		
			Map[a].edge.insert(b), Map[b].edge.insert(a);
		}

		bool isBio;
		stack<int> Stack;
		Map[0].color = 1, Stack.push(0);
        
		while (Stack.empty() == false) {

			int temp = Stack.top();
			isBio = true, Stack.pop();

			for (auto iter = Map[temp].edge.begin(); iter != Map[temp].edge.end(); ++iter) {

				if (Map[*iter].color == 0) { 
					
					Map[*iter].color = Map[temp].color*-1;
					Stack.push(*iter);
				}
				else {

					if (Map[*iter].color != Map[temp].color*-1) { isBio = false; break; }
				}
			}

			if (isBio == false) { break; }
		}
		
		isBio == true ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n";
	}

	return 0;
}
