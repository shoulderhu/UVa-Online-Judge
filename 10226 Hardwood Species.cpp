#include <iostream>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;

int main() {

	int i, kace;
	map<string, int> species;
	map<string, int>::iterator loop;
	string tree;

	scanf("%d", &kace), getchar(), getchar();

	for (i = 1; i <= kace; i++) {

		int trees = 0;		
		species.clear();

		while (getline(cin, tree)) { 
			
			if (tree[0] == '\0') { break; }
			species[tree]++, trees++;
		}		

		for (loop = species.begin(); loop != species.end(); loop++) {

			printf("%s %.4lf\n", (*loop).first.c_str(), (*loop).second / (double)trees * 100);			
		}	

		if (i != kace) { printf("\n"); }
	}

	return 0;
}
