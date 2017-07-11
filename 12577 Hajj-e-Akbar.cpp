#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	int kace = 0;
	string ritual;

	while (cin >> ritual && ritual != "*") {

		printf("Case %d: ", ++kace);
		printf(ritual == "Hajj" ? "Hajj-e-Akbar\n" : "Hajj-e-Asghar\n");
	}

	return 0;
}