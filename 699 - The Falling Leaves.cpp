#include <iostream>
#include <map>

using namespace std;

int value, Case = 0;
bool isRoot;
string line;
stringstream ss;
map<int, int> Map;

void getTree(int index) {
	
	if (isRoot) { isRoot = false; }
	else { cin >> value; }
	
	if (value == -1) { return; }
		
	Map[index] += value;
	getTree(index - 1);
	getTree(index + 1);	
}

int main() {

	ios::sync_with_stdio(false);
	
	while (cin >> value && value != -1) {
		
		isRoot = true, Map.clear(), getTree(0);
		
		cout << "Case " << ++Case << ":" << endl << Map.begin()->second;

		for (auto iter = ++Map.begin(); iter != Map.end(); ++iter) {

			cout << " " <<iter->second;
		}

		cout << endl << endl;
	}		
		
	return 0;
}