#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int num;
	string command;
	
	while (cin >> num && num != 0) {

		unordered_map<string, int> Die{ { "TOP", 1 },{ "NORTH", 2 },
					                    { "WEST", 3 },{ "DOWN", 6 },
		                                { "SOUTH", 5 },{ "EAST", 4 } };

		for (int i = 0; i < num; ++i) {

			cin >> command;

			switch (command[0]) {

			case 'n':
				Die["TOP"] = Die["SOUTH"]; 
				Die["SOUTH"] = Die["DOWN"];
				Die["DOWN"] = 7 - Die["TOP"];
				Die["NORTH"] = 7 - Die["SOUTH"];
				break;
			case 'e':
				Die["TOP"] = Die["WEST"];
				Die["WEST"] = Die["DOWN"];
				Die["DOWN"] = 7 - Die["TOP"];
				Die["EAST"] = 7 - Die["WEST"];
				break;
			case 's':
				Die["TOP"] = Die["NORTH"];
				Die["NORTH"] = Die["DOWN"];
				Die["DOWN"] = 7 - Die["TOP"];
				Die["SOUTH"] = 7 - Die["NORTH"];
				break;
			case 'w':
				Die["TOP"] = Die["EAST"];
				Die["EAST"] = Die["DOWN"];
				Die["DOWN"] = 7 - Die["TOP"];
				Die["WEST"] = 7 - Die["EAST"];
				break;
			}
		}

		cout << Die["TOP"] << endl;
	}
	
	return 0;
}