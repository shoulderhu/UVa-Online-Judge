#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int pos = 0;
	string sen[101];
	vector<int> length;

	while (getline(cin, sen[pos])) { length.push_back(sen[pos].size()), pos++; }
	
	for (int i = 0; i < (*max_element(length.begin(), length.end())); i++) {

		for (int j = pos - 1; j >= 0; j--) {

			if (i < length[j]) { printf("%c", sen[j][i]); }
			else { printf(" "); }
		}
		
		printf("\n");
	}

	return 0;
}
