#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	int i, n;
	string country, name;

	map<string, int> total;
	map<string, int> ::iterator loop;

	scanf("%d", &n), getchar();

	for (i = 1; i <= n; i++) {

		cin >> country;
		getline(cin, name);
		total[country]++;
	}

	for (loop = total.begin(); loop != total.end(); loop++) {

		printf("%s %d\n", loop->first.c_str(), loop->second);		
	}
		
	return 0;
}