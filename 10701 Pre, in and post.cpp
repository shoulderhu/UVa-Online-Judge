#include <iostream>
#include <string>

using namespace std;

int p;
struct node {

	char label;
	node *left, *right;
};
string S1, S2;

void postOrder(node *p) {

	if (p != NULL) {

		postOrder(p->left);
		postOrder(p->right);
		cout << p->label;
	}
}

node *binaryTree(int left, int right) {

	int mid;
	node *Node = new node;
	Node->label = S1[++p];

	if (left < right) {

		mid = S2.find(Node->label);

		if (left < mid) { Node->left = binaryTree(left, mid - 1); }
		else { Node->left = NULL; }

		if (mid < right) { Node->right = binaryTree(mid + 1, right); }
		else { Node->right = NULL; }
	}
	else { Node->left = NULL, Node->right = NULL; }

	return Node;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int C, N;
	
	cin >> C;

	for (int i = 1; i <= C; ++i) {

		cin >> N >> S1 >> S2;

		p = -1;
		node *root = binaryTree(0, N - 1);
		postOrder(root);
		cout << endl;
	}

	return 0;
}