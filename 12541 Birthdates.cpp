#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	struct person {

		string name;
		int year, month, date;
	}Person;
	vector<struct person> Vec;

	cin >> n;

	for (int i = 0; i < n; ++i) {

		cin >> Person.name >> Person.date >> Person.month >> Person.year;
		Vec.push_back(Person);
	}

	sort(Vec.begin(), Vec.end(), [](struct person a, struct person b) {
	
		if (a.year != b.year) { return a.year < b.year; }
		else if (a.month != b.month) { return a.month < b.month; }
		else { return a.date < b.date; }
	});

	cout << Vec[n - 1].name << endl << Vec[0].name << endl;

	return 0;
}