#include <iostream>
#include <stack>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int I;
	stack<int> binary;
	
	while (cin >> I && I != 0) {

		int P = 0;
		
		while (I > 0) {

			int temp = I % 2;
						
			binary.push(temp);
			P += temp, I /= 2;
		}

		cout << "The parity of ";

		while (binary.empty() == false) {

			cout << binary.top();			
			binary.pop();
		}
			
		cout << " is " << P << " (mod 2).\n";
	}

	return 0;
}