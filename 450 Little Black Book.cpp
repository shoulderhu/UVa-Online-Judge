#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int num;
	struct imformation {
		
		string title, firstName, lastName, street, home, work, box, department;
	}Im;
	size_t pos;
	string line;	
	vector<struct imformation> Vec;

	cin >> num, cin.ignore();

	for (int i = 0; i < num; ++i) {
				
		getline(cin, Im.department);

		while (getline(cin, line) && line != "") {

			pos = line.find(','), Im.title = line.substr(0, pos), line.erase(0, pos + 1);
			pos = line.find(','), Im.firstName = line.substr(0, pos), line.erase(0, pos + 1);
			pos = line.find(','), Im.lastName = line.substr(0, pos), line.erase(0, pos + 1);
			pos = line.find(','), Im.street = line.substr(0, pos), line.erase(0, pos + 1);
			pos = line.find(','), Im.home = line.substr(0, pos), line.erase(0, pos + 1);
			pos = line.find(','), Im.work = line.substr(0, pos), line.erase(0, pos + 1);
			Im.box = line;
			
			Vec.push_back(Im);
		}		
	}

	sort(Vec.begin(), Vec.end(), [](struct imformation &a, struct imformation &b) {

		return a.lastName < b.lastName;
	});

	for (int j = 0; j < Vec.size(); ++j) {
		
		cout << "----------------------------------------" << endl;
		cout << Vec[j].title << " " << Vec[j].firstName << " " << Vec[j].lastName << endl;
		cout << Vec[j].street << endl;
		cout << "Department: " << Vec[j].department << endl;
		cout << "Home Phone: " << Vec[j].home << endl;
		cout << "Work Phone: " << Vec[j].work << endl;
		cout << "Campus Box: " << Vec[j].box << endl;
	}

	return 0;
}