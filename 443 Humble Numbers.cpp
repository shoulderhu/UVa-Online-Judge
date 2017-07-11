#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <functional>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	vector<long long> humbleNumber;
	set<long long> Set;
	priority_queue<long long, vector<long long>, greater<long long>> Queue;		
	Queue.push(1), Set.insert(1);

	for (int i = 1; i <= 5842; ++i) {
		
		long long temp = Queue.top();

		humbleNumber.push_back(temp), Queue.pop();
		if (Set.find(temp * 2) == Set.end()) { Queue.push(temp * 2), Set.insert(temp * 2); }
		if (Set.find(temp * 3) == Set.end()) { Queue.push(temp * 3), Set.insert(temp * 3); }
		if (Set.find(temp * 5) == Set.end()) { Queue.push(temp * 5), Set.insert(temp * 5); }
		if (Set.find(temp * 7) == Set.end()) { Queue.push(temp * 7), Set.insert(temp * 7); }
	}
		
	while (cin >> n && n != 0) { 
		
		cout << "The " << n;

		if (n % 10 == 1 && n % 100 != 11) { cout << "st"; }
		else if (n % 10 == 2 && n % 100 != 12) { cout << "nd"; }
		else if (n % 10 == 3 && n % 100 != 13) { cout << "rd"; }
		else{ cout << "th"; }
				
		cout << " humble number is " << humbleNumber[n - 1] << "." << endl;
	}

	return 0;
}