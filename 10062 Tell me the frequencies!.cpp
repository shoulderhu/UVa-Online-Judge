#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool mySort(pair<int, int> &p1, pair<int, int> &p2) {

	if (p1.second != p2.second) { return p1.second < p2.second; }
	else if (p1.first != p2.first) { return p1.first > p2.first; }	
}

int main() {

	int kace = 0;	
	map<int, int> ASCII;	
	string line;

	while (getline(cin, line)) {

		ASCII.clear();

		if (++kace > 1) { printf("\n"); }

		for (int i = 0; i < line.size(); i++) { ASCII[line[i]]++; }

		vector<pair<int, int>> vec(ASCII.begin(), ASCII.end());
		vector<pair<int, int>>::iterator iter;

		sort(vec.begin(), vec.end(), mySort);

		for (iter = vec.begin(); iter != vec.end(); iter++) {

			printf("%d %d\n", iter->first, iter->second);
		}
	}

	return 0;
}