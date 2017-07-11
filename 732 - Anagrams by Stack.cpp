#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string source, target;
stack<char> Stack;
vector<string> sequence;

inline void DFS(string str, string seq, int i, int j) {

	if (str == target) {

		sequence.push_back(seq);
		return;
	}

	if (i < source.size()) {

		Stack.push(source[i]);
		seq.push_back('i');
		DFS(str, seq, i + 1, j);
		Stack.pop();
		seq.pop_back();
	}

	if (i > j && j < source.size()) {
		
		char t = Stack.top();
		if (t != target[j]) { return; }
		Stack.pop();
		str += t;
		seq.push_back('o');
		DFS(str, seq, i, j + 1);
		Stack.push(t);
		str.pop_back();
		seq.pop_back();		
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	while (cin >> source >> target) {
				
		sequence.clear();
		while (!Stack.empty()) { Stack.pop(); }

		DFS("", "", 0, 0);
		
		cout << "[\n";

		for (int i = 0; i < sequence.size(); ++i) {
			
			for (int j = 0; j < sequence[i].size(); ++j) {

				if (j != 0) { cout << ' '; }
				cout << sequence[i][j];
			}

			cout << '\n';
		}

		cout << "]\n";
	}

	return 0;
}