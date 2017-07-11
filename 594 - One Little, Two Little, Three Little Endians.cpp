#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	union num {

		int data;
		char byte[4];
	}Num;
		
	while (cin >> Num.data) {
				
		cout << Num.data << " converts to ";
		swap(Num.byte[0], Num.byte[3]);
		swap(Num.byte[1], Num.byte[2]);		
		cout << Num.data << '\n';
	}

	return 0;
}