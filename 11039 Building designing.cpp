#include <iostream>
#include <string>
#include <cstdlib>
#include <map>

using namespace std;

int main() {

	int i, j, p, floors, floor;
	map<int, string> building;

	while (cin >> p) {
		
		for (i = 1; i <= p; i++) {
						
			building.clear();

			cin >> floors;

			for (j = 1; j <= floors; j++) {

				cin >> floor;

				floor > 0 ? building[floor] = "blue" : building[abs(floor)] = "red";
			}

			map<int, string>::reverse_iterator loop = building.rbegin();

			int high = 1;
			string color = loop->second;

			for (loop = building.rbegin(); loop != building.rend(); loop++) {
				
				if (color != loop->second) {

					high++;
					color = loop->second;
				}
			}		

			cout << high << endl;
		}		
	}

	return 0;
}