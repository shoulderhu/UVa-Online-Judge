#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

bool mySort(char a, char b) { 
	
	char lowerA = tolower(a), lowerB = tolower(b);
	
	if (lowerA == lowerB) { return a < b; }
	else { return lowerA < lowerB; }
 }

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int num;
	string word;

	cin >> num;

	for (int i = 1; i <= num; ++i) {

		cin >> word;

		sort(word.begin(), word.end(), mySort);

		do {
			cout << word << endl;
			
		} while (next_permutation(word.begin(), word.end(), mySort) == true);
	}

	return 0;
}