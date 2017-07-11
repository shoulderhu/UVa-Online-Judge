#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int In[10000], Post[10000], i, leaf, len, path;
struct node {

	int value;
	struct node *left, *right;
}*root;
string line;
stringstream ss;

node* getTree(int left, int right, int route) {

	node *Node = new node;
	Node->value = Post[--i];
	route += Node->value;

	if (left < right) {

		int p = find(In, In + len, Node->value) - In;

		if (p < right) { Node->right = getTree(p + 1, right, route); }
		else { Node->right = NULL; }

		if (left < p) { Node->left = getTree(left, p - 1, route); }
		else { Node->left = NULL; }
	}
	else {

		Node->left = NULL;
		Node->right = NULL;

		if (route < path) { path = route, leaf = Node->value; }
		else if (route == path) { leaf = min(leaf, Node->value); }
	}

	return Node;
}

int main() {

	ios::sync_with_stdio(false);
	
	while (getline(cin, line)) {

		i = -1, leaf = 10000, path = 2000000000, ss.clear(), ss << line;

		while (ss >> In[++i]);
		for (int j = 0; j < i; ++j) { cin >> Post[j]; }
		cin.ignore(), len = i;
		
		root = getTree(0, i - 1, 0);
		
		cout << leaf << endl;
	}

	return 0;
}