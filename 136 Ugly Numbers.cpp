#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <functional>

using namespace std;

int main() {

	long long int ugly;
	set<long long int> Set;
	priority_queue<long long int, vector<long long int>, greater<long long int>> uglyNumber;
	uglyNumber.push(1), Set.insert(1);

	for (int i = 1; i <= 1500; i++) {

		ugly = uglyNumber.top();
		
		if (Set.find(ugly * 2) == Set.end()) { Set.insert(ugly * 2), uglyNumber.push(ugly * 2); }
		if (Set.find(ugly * 3) == Set.end()) { Set.insert(ugly * 3), uglyNumber.push(ugly * 3); }
		if (Set.find(ugly * 5) == Set.end()) { Set.insert(ugly * 5), uglyNumber.push(ugly * 5); }
		
		uglyNumber.pop();
	}

	printf("The 1500'th ugly number is %lld.\n", ugly);

	return 0;
}
