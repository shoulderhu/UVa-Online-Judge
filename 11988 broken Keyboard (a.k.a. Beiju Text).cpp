#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {

	int i;
	string typing;
	list<char> BeijuText;	

	while (cin >> typing) {
				
		BeijuText.clear();
		list<char>::iterator loop, pointer = BeijuText.begin();

		for (i = 0; i < typing.size(); i++) {

			if (typing[i] == '[') { pointer = BeijuText.begin(); }
			else if (typing[i] == ']') { pointer = BeijuText.end(); }
			else { BeijuText.insert(pointer, typing[i]); }
		}
		
		for (loop = BeijuText.begin(); loop != BeijuText.end(); loop++) { 
			
			cout << *loop; 
		}

		cout << endl;
	}

	return 0;
}
