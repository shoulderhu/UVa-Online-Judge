#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T;	
	struct line {
	
		int relevance;
		string webPage;
	}Line;
	vector<struct line> table;

	scanf("%d", &T), getchar();

	for (int i = 1; i <= T; i++) {

		int Max = 0;
		table.clear();

		for (int j = 1; j <= 10; j++) {

			cin >> Line.webPage >> Line.relevance;
			table.push_back(Line);
			Max = max(Max, Line.relevance);
		}

		printf("Case #%d:\n", i);

		for (int i = 0; i < table.size(); i++) {

			if (table[i].relevance == Max) { printf("%s\n", table[i].webPage.c_str()); }
		}
	}

	return 0;
}