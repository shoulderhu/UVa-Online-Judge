#include <iostream>
#include <iterator>
#include <list>

using namespace std;

bool isLast(list<int> city, int i) {
		
	while (city.size() != 1) {
		
		if (city.front() == 2) { return false; }
		else { city.pop_front(); }

		for (int j = 1; j < i; ++j) { 
			
			city.push_back(city.front());
			city.pop_front();		
		}		
	}

	if (*city.begin() == 2) { return true; }
	else { return false; }
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	
	while (cin >> n && n != 0) { 
	
		list<int> city;
		for (int i = 1; i <= n; ++i) { city.push_back(i); }

		for (int i = 2; ; ++i) {

			if (isLast(city, i) == true) { cout << i << endl; break; }
		}
	}
	
	return 0;
}