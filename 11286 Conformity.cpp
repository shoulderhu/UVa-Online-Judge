#include <stdio.h>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {

	int i, j, n, course;
	set<int> courses;
	map<set<int>, int> combination;

	while (cin >> n && n != 0) {
		
		int total = 0, max = 0;
	    combination.clear();

		for (i = 1; i <= n; i++) {

			courses.clear();

			for (j = 1; j <= 5; j++) {

				cin >> course;
				courses.insert(course);
			}
			
			combination[courses]++;
			if (combination[courses] > max) { max = combination[courses]; }
		}
				
		map<set<int>, int>::iterator loop, loopE = combination.end();

		for (loop = combination.begin(); loop != combination.end(); loop++) {

			if (max == loop->second) { total+=loop->second; }
		}

		printf("%d\n", total);
	}	

	return 0;
}