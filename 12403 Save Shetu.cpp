#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	int T, money, total = 0;
	string operation;

	scanf("%d", &T), getchar();

	for (int i = 1; i <= T; i++) {

		cin >> operation;

		if (operation == "donate") { 
			
			scanf("%d", &money);
			total += money; 
		}
		else if (operation == "report") { printf("%d\n", total); }	
	}

	return 0;
}