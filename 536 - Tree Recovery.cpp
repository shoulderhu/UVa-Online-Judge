#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int pre = -1, pos;
struct node {

	char value;
	node *left, *right;
}*root;
string preord, inord;

node* getTree(int left, int right) {

	node *Node = new node;
	Node->value = preord[++pre];

	if (left < right) {

		int pos = find(inord.begin(), inord.end(), Node->value) - inord.begin();

		if (left < pos) { Node->left = getTree(left, pos - 1); }
		else { Node->left = NULL; }
		
		if (pos < right) { Node->right = getTree(pos + 1, right); }
		else { Node->right = NULL; }
	}
	else {

		Node->left = NULL;
		Node->right = NULL;
	}

	return Node;
}

void postOrder(node *Node) {

	if (Node != NULL) {

		postOrder(Node->left);
		postOrder(Node->right);
		cout << Node->value;
	}
}

int main() {

	ios::sync_with_stdio(false);
	
	while (cin >> preord >> inord) {

		pre = -1;
		root = getTree(0, inord.size() - 1);
		postOrder(root);
		cout << endl;
	}

	return 0;
}