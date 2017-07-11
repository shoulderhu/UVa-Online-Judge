#include <iostream>

using namespace std;

int days, DD, MM, YYYY;
int month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isLeapYear() {

	if ((YYYY % 4 == 0 && YYYY % 100 != 0) || YYYY % 400 == 0) { 
		
		return true;
	}
	else{ return false; }	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);	

	while (cin >> days >> DD >> MM >> YYYY && 
		   (days != 0 || DD != 0 || MM != 0 || YYYY != 0)) {

		DD += days;		
		isLeapYear() ? month[2] = 29 : month[2] = 28;
		
		for (int i = MM; ; ++i) {

			if (i == 13) { 

				i = 1, ++YYYY; 
				isLeapYear() ? month[2] = 29 : month[2] = 28;
			}

			if (DD > month[i]) { DD -= month[i]; }
			else { cout << DD << " " << i << " " << YYYY << endl; break; }
		}		
	}


	return 0;
}