#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

map<char, int> list;
set<int> Set;

bool isTyped(string& line) {

	set<char> temp(line.begin(), line.end());
		
	for (auto iter = temp.begin(); iter != temp.end(); ++iter) {

		if (*iter == ' ' && Set.find(5) == Set.end() && Set.find(6) == Set.end()) { return false; }
		else if (Set.find(list[*iter]) == Set.end()) { return false; }		
	}

	return true;
}

struct mySort{

	bool operator()(string a, string b) {

		int aSize = a.size(), bSize = b.size();

		if (aSize != bSize) { return aSize > bSize; }
		else { return a < b; }
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int F, N, f, finger[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	string line;	
	
	list['q'] = 1, list['a'] = 1, list['z'] = 1,
	list['w'] = 2, list['s'] = 2, list['x'] = 2;
	list['e'] = 3, list['d'] = 3, list['c'] = 3;
	list['r'] = 4, list['f'] = 4, list['v'] = 4;
	list['t'] = 4, list['g'] = 4, list['b'] = 4;
	list['y'] = 7, list['h'] = 7, list['n'] = 7;
	list['u'] = 7, list['j'] = 7, list['m'] = 7;
	list['i'] = 8, list['k'] = 8, list[','] = 8;
	list['o'] = 9, list['l'] = 9, list['.'] = 9;
	list['p'] = 10, list[';'] = 10, list['/'] = 10;

	while (cin >> F >> N) {

		set<string, mySort> type;
		Set.clear(), Set.insert(finger, finger + 10);
		
		for(int i = 1; i<=F; ++i){
		
			cin >> f;
			Set.erase(f);
		}

		cin.ignore(1024, '\n');

		for (int i = 1; i <= N; ++i) {

			getline(cin, line);			
			if (isTyped(line) == true) { type.insert(line); }
		}
						
		if (type.empty() == true) { cout << "0" << endl; }
		else {

			int length = type.begin()->size(), num = 1;

			for (auto iter = ++type.begin(); iter != type.end(); ++iter) {

				if (iter->size() == length) { ++num; }
				else { break; }
			}

			cout << num << endl;
			for (auto iter = type.begin(); iter != type.end() && num >= 1; ++iter, --num) {
				
				cout << *iter << endl;
			}
		}		
	}

	return 0;
}