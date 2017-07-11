#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	bool isBL = false;
	size_t posC1, posC2, posR1, posR2;
	string column1, column2, row1, row2;

	while (cin >> row1 && row1 != "#") {

		if (isBL == false) { isBL = true; }
		else { cout << endl; }

		cin >> column1 >> row2 >> column2;

		bool isFound1 = false, isFound2 = false;

		for (int i = 0; i < row1.size(); ++i) {

			if ((posC1 = column1.find(row1[i])) != string::npos) {

				posR1 = i, isFound1 = true;
				break;
			}
		}

		for (int i = 0; i < row2.size(); ++i) {

			if ((posC2 = column2.find(row2[i])) != string::npos) {

				posR2 = i, isFound2 = true;
				break;
			}
		}

		if (posC1 == string::npos || posC2 == string::npos) {

			cout << "Unable to make two crosses" << endl;
			continue;
		}
		
		if (posC1 < posC2) { 
			
			for (int i = 0; i < posC2 - posC1; ++i) { column1.insert(0, " "); }	
			posC1 += posC2 - posC1;
		}
		else { for (int i = 0; i < posC1 - posC2; ++i) { column2.insert(0, " "); } }

		int Max = max(column1.size(), column2.size());

		for (int i = 0; i < Max; ++i) {

			if (i == posC1) { cout << row1 << "   " << row2 << endl; }
			else if (i < column1.size() && i < column2.size()) {

				if (column1[i] != ' ') {

					for (int j = 0; j < posR1; ++j) { cout << " "; }
					cout << column1[i];

					if (column2[i] == ' ') { cout << endl; }
					else {												
						
						for (int j = 0; j < row1.size() - posR1 + posR2 + 2; ++j) { cout << " "; }
						cout << column2[i] << endl;
					}					
				}
				else {

					for (int j = 0; j < row1.size() + 3 + posR2; ++j) { cout << " "; }
					cout << column2[i] << endl;
				}
			}
			else if (i >= column1.size()) {
			
				for (int j = 0; j < row1.size() + 3 + posR2; ++j) { cout << " "; }
				cout << column2[i] << endl;
			}
			else if (i >= column2.size()) {

				for (int j = 0; j < posR1; ++j) { cout << " "; }
				cout << column1[i] << endl;
			}
		}
	}

	return 0;
}