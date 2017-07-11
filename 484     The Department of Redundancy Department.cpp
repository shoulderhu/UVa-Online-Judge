#include <stdio.h>
#include <map>
#include <list>

using namespace std;

int main() {
	
	int integer;
	map<int, int> occurance;
	list<int> sequence;
	list<int>::iterator loop;

	while (scanf("%d", &integer) != EOF) {

		if (find(sequence.begin(), sequence.end(), integer) == sequence.end()) {

			sequence.push_back(integer);
		}
		
		occurance[integer]++;		
	}

	for (loop = sequence.begin(); loop != sequence.end(); loop++) {

		printf("%d %d\n", *loop, occurance[*loop]);
	}

	return 0;
}