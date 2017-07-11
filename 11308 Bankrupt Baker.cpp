#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct recipe {

	int cost = 0;
	string name;
};

bool mySort(struct recipe a, struct recipe b) {

	if (a.cost != b.cost) { return a.cost < b.cost; }
	else{
		
		string lowA = a.name, lowB = b.name;

		transform(lowA.begin(), lowA.end(), lowA.begin(), ::tolower);
		transform(lowB.begin(), lowB.end(), lowB.begin(), ::tolower);

		return lowA < lowB;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, m, n, b, c, k;	
	string title, ingred;

	cin >> t, cin.ignore();

	for (int i = 1; i <= t; ++i) {

		getline(cin, title);
		cin >> m >> n >> b, cin.ignore();

		map<string, int> ingredient;
		vector<struct recipe> Vector;
 		transform(title.begin(), title.end(), title.begin(), ::toupper);

		for (int j = 1; j <= m; ++j) {

			cin >> ingred >> c, cin.ignore();
			ingredient[ingred] = c;
		}

		for (int j = 1; j <= n; ++j) {

			struct recipe Recipe;

			getline(cin, Recipe.name);
			cin >> k, cin.ignore();

			for (int l = 1; l <= k; ++l) {

				cin >> ingred >> c, cin.ignore();
				Recipe.cost += ingredient[ingred] * c;
			}

			if (Recipe.cost <= b) { Vector.push_back(Recipe); }
		}

		cout << title << endl;

		if (Vector.empty() == true) { cout << "Too expensive!\n"; }
		else {
					
			sort(Vector.begin(), Vector.end(), mySort);

			for (auto iter = Vector.begin(); iter != Vector.end(); ++iter) {

				cout << iter->name << endl;
			}
		}

		cout << endl;
	}

	return 0;
}